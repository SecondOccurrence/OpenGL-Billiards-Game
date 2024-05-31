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

#include "../../globals/objects.h"
#include "../../globals/camera.h"

#include <math.h>

#include <stdio.h>

// TODO: massive refactor this is all spaghetti

void checkPockets(int objectBallsSize) {
    const int pockets = 6;

    Point3 cameraOrigin = {-4.0f, 0.5f, 0.0f};
    Point3 cueBallSpawn = {-2.5f, 0.1f, 0.0f};
    // for the cue ball
    for(int i = 0; i < pockets; i++) {
        int collision = collidesWithPocket(&cueBall, &table.pockets[i]);
        if(collision == 1) {
            for(int j = 0; j < 3; j++) {
                camera.position[j] = cameraOrigin[j];
                potentialCameraPosition[j] = cameraOrigin[j];
                cueBall.ball.position[j] = cueBallSpawn[j];
                cueBall.velocity[j] = 0.0f;
            }
        }
    }

    // for the object balls
    for(int i = 0; i < pockets; i++) {
        for(int j = 0; j < objectBallsSize; j++) {
            int collision = collidesWithPocket(&balls[j], &table.pockets[i]);
            if(collision == 1) {
                Point3 pocketPoint = {0.0f, -2.0f, 0.0f};
                for(int k = 0; k < 3; k++) {
                    balls[j].ball.position[k] = pocketPoint[k];
                }
            }
        }
    }
}

void ballMovement(int objectBallsSize, float seconds) {
    const Vector3 gravity = {0.0f, -7.5f, 0.0f};
    const GLfloat velocityThreshold = 0.1f;

    PlaneProperties collider;
    int tableWallSize = sizeof(table.colliders) / sizeof(table.colliders[0]);
    for(int i = 0; i < tableWallSize; i++) {
        collider = table.colliders[i];
        ballPlaneCollision(&cueBall, &collider, i);
        for(int j = 0; j < objectBallsSize; j++) {
            ballPlaneCollision(&balls[j], &collider, i);
        }
    }

    for(int i = 0; i < objectBallsSize; i++) {
        ballToBallCollision(&cueBall, &balls[i]);

        for(int j = i; j < objectBallsSize; j++) {
            if(i != j) {
                ballToBallCollision(&balls[i], &balls[j]);
            }
            // check every other ball if the two are colliding
        }
    }

    // TODO: function to impose gravity
    cueBall.velocity[1] += gravity[1] * seconds;
    for(int i = 0; i < objectBallsSize; i++) {
        balls[i].velocity[1] += gravity[1] * seconds;
    }

    // TODO: refactor this
    for(int i = 0; i < 3; i++) {
        if(fabsf(cueBall.velocity[i]) < velocityThreshold) {
            cueBall.velocity[i] = 0.0f;
        }
        for(int j = 0; j < objectBallsSize; j++) {
            if(fabsf(balls[j].velocity[i]) < velocityThreshold) {
                balls[j].velocity[i] = 0.0f;
            }
        }

        cueBall.ball.position[i] += cueBall.velocity[i] * seconds;

        for(int j = 0; j < objectBallsSize; j++) {
            balls[j].ball.position[i] += balls[j].velocity[i] * seconds;
        }
    }
}

void rotateCameraContinuous(RotationFlag* rotationFlag, float changeInSeconds) {
    double rotationSpeed = 60.0;
    if(*rotationFlag == ROTATION_CLOCKWISE) {
        rotateCameraClockwise(&camera, rotationSpeed * changeInSeconds);
    }
    else if(*rotationFlag == ROTATION_ANTICLOCKWISE) {
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

void updateCameraPosition(int* previousMoveCheck, float deltaTime) {
    int isCurrentlyMoving = 0;

    Vector3 velocity = {cueBall.velocity[0], cueBall.velocity[1], cueBall.velocity[2]};
    if(velocity[0] != 0.0f || velocity[2] != 0.0f) {
        isCurrentlyMoving = 1;
    }

    potentialCameraPosition[0] += cueBall.velocity[0] * deltaTime;
    potentialCameraPosition[2] += cueBall.velocity[2] * deltaTime;

    if(*previousMoveCheck == 1 && isCurrentlyMoving == 0) {
        resetCamera(&camera, &cueBall.ball.position, &potentialCameraPosition);
    }
    else if(*previousMoveCheck == 0 && isCurrentlyMoving == 1) {
        viewTop(&camera);
    }

    *previousMoveCheck = isCurrentlyMoving;
}

void resetCamera(Camera* camera, Point3* newLookat, Point3* newPosition) {
    Point3 newUp = {0.0f, 1.0f, 0.0f};
    for (int i = 0; i < 3; ++i) {
        camera->position[i] = (*newPosition)[i];
        camera->lookat[i] = (*newLookat)[i];
        camera->up[i] = newUp[i];
    }
}
