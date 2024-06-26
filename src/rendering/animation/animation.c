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

#include <math.h>

void prepareForHit(CueHitFlag* cueHitFlag, float* spacebarHoldTime, const float* maxPower, Ball* cueBall, Camera* camera) {
    const float powerIncrement = 1.0f;

    if(*cueHitFlag == CHARGING_SHOT) {
        if(*spacebarHoldTime < *maxPower - 0.01f) {
            *spacebarHoldTime += powerIncrement;
        }
    }
    else if(*cueHitFlag == HIT) {
        Vector3 direction;
        calculateVelocityDirection(&direction, camera, cueBall);
        cueBall->velocity[0] += direction[0] * *spacebarHoldTime;
        cueBall->velocity[2] += direction[2] * *spacebarHoldTime;

        *spacebarHoldTime = 0.0f;

        *cueHitFlag = IDLE;
    }
}

void checkPockets(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize, Camera* camera) {
    const int pockets = 6;

    const Point3 cameraOrigin = {-4.0f, 0.5f, 0.0f};
    const Point3 cueBallSpawn = {-2.5f, 0.1f, 0.0f};

    int collisionFound;
    for(int i = 0; i < pockets; i++) {
        collisionFound = collidesWithPocket(cueBall, &table->pockets[i]);
        if(collisionFound == 1) {
            for(int j = 0; j < 3; j++) {
                camera->position[j] = cameraOrigin[j];
                camera->potentialCameraPosition[j] = cameraOrigin[j];
                cueBall->ball.position[j] = cueBallSpawn[j];
                cueBall->velocity[j] = 0.0f;
            }
        }

        for(int j = 0; j < objectBallsSize; j++) {
            collisionFound = collidesWithPocket(&objectBalls[j], &table->pockets[i]);
            if(collisionFound == 1) {
                Point3 pocketPoint = {0.0f, -2.0f, 0.0f};
                for(int k = 0; k < 3; k++) {
                    objectBalls[j].ball.position[k] = pocketPoint[k];
                }
                objectBalls[j].pocketed = 1;
            }
        }
    }
}

void checkForCollisions(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize) {
    PlaneProperties collider;
    int tableWallSize = sizeof(table->colliders) / sizeof(table->colliders[0]);
    for(int i = 0; i < tableWallSize; i++) {
        collider = table->colliders[i];
        ballPlaneCollision(cueBall, &collider, i);
        for(int j = 0; j < objectBallsSize; j++) {
            ballPlaneCollision(&objectBalls[j], &collider, i);
        }
    }

    for(int i = 0; i < objectBallsSize; i++) {
        ballToBallCollision(cueBall, &objectBalls[i]);

        for(int j = i + 1; j < objectBallsSize; j++) {
            ballToBallCollision(&objectBalls[i], &objectBalls[j]);
        }
    }
}

void ballMovement(Ball* cueBall, Ball* objectBalls, int objectBallsSize, float seconds) {
    const GLfloat gravity = -7.5f;

    updateVelocity(cueBall, gravity, seconds);

    for(int i = 0; i < objectBallsSize; i++) {
        updateVelocity(&objectBalls[i], gravity, seconds);
    }
}

void updateVelocity(Ball* ball, GLfloat gravity, float seconds) {
    const GLfloat velocityThreshold = 0.1f;

    ball->velocity[1] += gravity * seconds;
    for(int i = 0; i < 3; i++) {
        if(fabsf(ball->velocity[i]) < velocityThreshold) {
            ball->velocity[i] = 0.0f;
        }

        ball->ball.position[i] += ball->velocity[i] * seconds;
    }
}

void rotateCameraContinuous(RotationFlag* rotationFlag, Camera* camera, Ball* cueBall, float changeInSeconds) {
    double rotationSpeed = 60.0;
    if(*rotationFlag == ROTATION_CLOCKWISE) {
        rotateCameraClockwise(camera, cueBall, rotationSpeed * changeInSeconds);
    }
    else if(*rotationFlag == ROTATION_ANTICLOCKWISE) {
        rotateCameraCounterclockwise(camera, cueBall, rotationSpeed * changeInSeconds);
    }
}

void rotateCameraClockwise(Camera* camera, Ball* cueBall, float angle) {
    float radians = angle * (M_PI / 180.0);

    Vector3 direction;
    subtractVectors(direction, cueBall->ball.position, camera->position);

    // Normalize the direction vector
    float distance = sqrt(direction[0] * direction[0] + direction[2] * direction[2]);
    direction[0] /= distance;
    direction[2] /= distance;

    // Calculate the new position
    float newX = direction[0] * cos(radians) - direction[2] * sin(radians);
    float newZ = direction[0] * sin(radians) + direction[2] * cos(radians);

    // Scale the new direction to maintain the same distance from the ball
    camera->position[0] = cueBall->ball.position[0] - newX * distance;
    camera->position[2] = cueBall->ball.position[2] - newZ * distance;
}

void rotateCameraCounterclockwise(Camera* camera, Ball* cueBall, float angle) {
    float radians = angle * (M_PI / 180.0);

    Vector3 direction;
    subtractVectors(direction, cueBall->ball.position, camera->position);

    // Normalize the direction vector
    float distance = sqrt(direction[0] * direction[0] + direction[2] * direction[2]);
    direction[0] /= distance;
    direction[2] /= distance;

    // Calculate the new position
    float newX = direction[0] * cos(radians) + direction[2] * sin(radians);
    float newZ = -direction[0] * sin(radians) + direction[2] * cos(radians);

    // Scale the new direction to maintain the same distance from the ball
    camera->position[0] = cueBall->ball.position[0] - newX * distance;
    camera->position[2] = cueBall->ball.position[2] - newZ * distance;
}

void updateCameraPosition(int* previousMoveCheck, Camera* camera, Ball* cueBall, float deltaTime) {
    int isCurrentlyMoving = 0;

    Vector3 velocity = {cueBall->velocity[0], cueBall->velocity[1], cueBall->velocity[2]};
    if(velocity[0] != 0.0f || velocity[2] != 0.0f) {
        isCurrentlyMoving = 1;
    }

    camera->potentialCameraPosition[0] += cueBall->velocity[0] * deltaTime;
    camera->potentialCameraPosition[1] = 0.5f;
    camera->potentialCameraPosition[2] += cueBall->velocity[2] * deltaTime;

    if(*previousMoveCheck == 1 && isCurrentlyMoving == 0) {
        resetCamera(camera, &cueBall->ball.position);
    }
    else if(*previousMoveCheck == 0 && isCurrentlyMoving == 1) {
        viewTop(camera);
    }

    *previousMoveCheck = isCurrentlyMoving;
}

void resetCamera(Camera* camera, Point3* newLookat) {
    Point3 newUp = {0.0f, 1.0f, 0.0f};
    for (int i = 0; i < 3; ++i) {
        camera->position[i] = camera->potentialCameraPosition[i];
        camera->lookat[i] = (*newLookat)[i];
        camera->up[i] = newUp[i];
    }
}
