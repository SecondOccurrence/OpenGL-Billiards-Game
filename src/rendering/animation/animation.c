/*
 * FILE: animation.h
 * PURPOSE: animation function definitions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (06/05/2024): added function to impose gravity on object
 *   Contributed by Josh S, 34195182
 * - v1.2 (07/05/2024): ballMovement now updates the balls position given all axis velocity
 *   Contributed by Josh S, 34195182
 * - v1.3 (08/05/2024): added ability to start/stop animation
 *   Contributed by Josh S, 34195182
 * - v1.3 (14/05/2024): added the camera rotation code and global variables
 *   Contributed by Abhijeet S, 34777306
 */

#include "animation.h"

#include "../../data_structures/flags.h"
#include "../../math/collision.h"
#include "../../math/vector_operations.h"
#include "../../input/keyboard_utils.h"

#include "../../globals/flags.h"
#include "../../globals/objects.h"
#include "../../globals/camera.h"
#include "../../globals/general.h"

#include <math.h>

extern const int TIMERMSECS;

void animate() {
    const int targetFrameRate = 60;

    currentFrameTime = glutGet(GLUT_ELAPSED_TIME);
    float changeInSeconds = (currentFrameTime - previousFrameTime) / 1000.0f;

    float targetFrameTime = 1.0f / targetFrameRate;
    if(changeInSeconds >= targetFrameTime) {
        callAnimations(changeInSeconds);
        
        previousFrameTime = currentFrameTime;
    }

    glutPostRedisplay();
}

void callAnimations(float deltaTime) {
    if(animation_flag == ANIMATION_ENABLED) {
        ballMovement(deltaTime);

        rotateCameraContinuous(deltaTime);

        updateCameraPosition(deltaTime);
    }
}

float posX = 0;
float posZ = 0;

void updateCameraPosition(float deltaTime) {
    int isCurrentlyMoving = 0;

    Vector3 velocity = {cueBall.velocity[0], cueBall.velocity[1], cueBall.velocity[2]};
    if(velocity[0] != 0.0f || velocity[2] != 0.0f) {
        isCurrentlyMoving = 1;
    }

    cueBall.cameraPosition[0] += cueBall.velocity[0] * deltaTime;
    cueBall.cameraPosition[2] += cueBall.velocity[2] * deltaTime;

    if(previousMoveCheck == 1 && isCurrentlyMoving == 0) {
        resetCamera(&camera, &cueBall.ball.position, &cueBall.cameraPosition);
    }
    else if(previousMoveCheck == 0 && isCurrentlyMoving == 1) {
        viewTop(&camera);
    }

    previousMoveCheck = isCurrentlyMoving;
}

void resetCamera(Camera* camera, Point3* newLookat, Point3* newPosition) {
    Point3 newUp = {0.0f, 1.0f, 0.0f};
    for (int i = 0; i < 3; ++i) {
        camera->position[i] = (*newPosition)[i];
        camera->lookat[i] = (*newLookat)[i];
        camera->up[i] = newUp[i];
    }
}

void ballMovement(float seconds) {
    const Vector3 gravity = {0.0f, -7.5f, 0.0f};
    const float collisionOffset = 0.2f;
    const GLfloat velocityThreshold = 0.1f;


    GLfloat distance;
    PlaneProperties collider;
    GLfloat velocity;
    int tableWallSize = sizeof(table.colliders) / sizeof(table.colliders[0]);
    for(int i = 0; i < tableWallSize; i++) {
        collider = table.colliders[i];
        distance = distanceToPlane(cueBall.ball.position, collider.points[0], collider.points[1], collider.points[2]);

        if(distance < (cueBall.ball.radius)) {
            Vector3 planeNormal;
            calcUnitNormal(planeNormal, collider.points[0], collider.points[1], collider.points[2]);

            GLfloat perpendicular = calcDotProduct(cueBall.velocity, planeNormal);

            for(int j = 0; j < 3; j++) {
                velocity = cueBall.velocity[j] - 2 * perpendicular * planeNormal[j];
                if(velocity > velocityThreshold) {
                    velocity *= collider.bounciness;
                }
                cueBall.velocity[j] = velocity;
            }

            cueBall = resolveCollision(&cueBall, distance, planeNormal, i);
        }

    }
    cueBall.velocity[1] += gravity[1] * seconds;


    for(int i = 0; i < 3; i++) {
        if(fabsf(cueBall.velocity[i]) < velocityThreshold) {
            cueBall.velocity[i] = 0.0f;
        }

        cueBall.ball.position[i] += cueBall.velocity[i] * seconds;
    }
}

void rotateCameraContinuous(float changeInSeconds) {
    double rotationSpeed = 60.0;
    if (rotation_flag_c == ROTATION_ENABLED) {
        rotateCameraClockwise(&camera, rotationSpeed * changeInSeconds);
    }
    else if (rotation_flag_a == ROTATION_ENABLED) {
        rotateCameraCounterclockwise(&camera, rotationSpeed * changeInSeconds);
    }
}

void rotateCameraClockwise(Camera* camera, float angle) {
    float radians = angle * (M_PI / 180.0);

    Vector3 direction;
    subtractVectors(direction, cueBall.ball.position, camera->position);

    // Normalize the direction vector
    float distance = sqrt(direction[0] * direction[0] + direction[2] * direction[2]);
    direction[0] /= distance;
    direction[2] /= distance;

    // Calculate the new position
    float newX = direction[0] * cos(radians) - direction[2] * sin(radians);
    float newZ = direction[0] * sin(radians) + direction[2] * cos(radians);

    // Scale the new direction to maintain the same distance from the ball
    camera->position[0] = cueBall.ball.position[0] - newX * distance;
    camera->position[2] = cueBall.ball.position[2] - newZ * distance;
}

void rotateCameraCounterclockwise(Camera* camera, float angle) {
    float radians = angle * (M_PI / 180.0);

    Vector3 direction;
    subtractVectors(direction, cueBall.ball.position, camera->position);

    // Normalize the direction vector
    float distance = sqrt(direction[0] * direction[0] + direction[2] * direction[2]);
    direction[0] /= distance;
    direction[2] /= distance;

    // Calculate the new position
    float newX = direction[0] * cos(radians) + direction[2] * sin(radians);
    float newZ = -direction[0] * sin(radians) + direction[2] * cos(radians);

    // Scale the new direction to maintain the same distance from the ball
    camera->position[0] = cueBall.ball.position[0] - newX * distance;
    camera->position[2] = cueBall.ball.position[2] - newZ * distance;
}
