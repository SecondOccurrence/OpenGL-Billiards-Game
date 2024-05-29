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

#include "../../globals/flags.h"
#include "../../globals/objects.h"
#include "../../globals/camera.h"
#include "../../globals/general.h"


#include <math.h>

extern const int TIMERMSECS;

#include <stdio.h>

float accumulatedTime = 0;

void animate() {
    const int targetFrameRate = 60;

    currentFrameTime = glutGet(GLUT_ELAPSED_TIME);
    float changeInSeconds = (currentFrameTime - previousFrameTime) / 1000.0f;

    float targetFrameTime = 1.0f / targetFrameRate;
    if(changeInSeconds >= targetFrameTime) {
        if(animation_flag == ANIMATION_ENABLED) {
            ballMovement(changeInSeconds);

            rotateCameraContinuous(changeInSeconds);
        }
        previousFrameTime = currentFrameTime;
    }

    glutPostRedisplay();
}

void ballMovement(float seconds) {
    const Vector3 gravity = {0.0f, -7.5f, 0.0f};

    GLfloat distance = distanceToPlane(ballProperties.ball.position, planeProperties.points[0], planeProperties.points[1], planeProperties.points[2]);
    if(distance < ballProperties.ball.radius) {
        Vector3 planeNormal;
        calcUnitNormal(planeNormal, planeProperties.points[0], planeProperties.points[1], planeProperties.points[2]);

        GLfloat perpendicular = calcDotProduct(ballProperties.velocity, planeNormal);

        for(int i = 0; i < 3; i++) {
            ballProperties.velocity[i] = (ballProperties.velocity[i] - 2 * perpendicular * planeNormal[i]) * planeProperties.bounciness;
        }

        ballProperties = resolveCollision(&ballProperties, distance, planeNormal);
    }

    ballProperties.velocity[1] += gravity[1] * seconds;

    const GLfloat threshold = 0.005f;
    for(int i = 0; i < 3; i++) {
        if(fabsf(ballProperties.velocity[i]) < threshold) {
            ballProperties.velocity[i] = 0.0f;
        }

        ballProperties.ball.position[i] += ballProperties.velocity[i] * seconds;
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
    subtractVectors(direction, camera->lookat, camera->position);

    float newX = direction[0] * cos(radians) - direction[2] * sin(radians);
    float newZ = direction[0] * sin(radians) + direction[2] * cos(radians);

    camera->position[0] = camera->lookat[0] - newX;
    camera->position[2] = camera->lookat[2] - newZ;
}

void rotateCameraCounterclockwise(Camera* camera, float angle) {
    float radians = angle * (M_PI / 180.0);

    Vector3 direction;
    subtractVectors(direction, camera->lookat, camera->position);

    float newX = direction[0] * cos(radians) + direction[2] * sin(radians);
    float newZ = -direction[0] * sin(radians) + direction[2] * cos(radians);

    camera->position[0] = camera->lookat[0] - newX;
    camera->position[2] = camera->lookat[2] - newZ;
}
