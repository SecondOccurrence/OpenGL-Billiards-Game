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
 * - v1.2 (08/05/2024): added physics for ball moving down sloped plane
 *
 */


#ifndef animation_h
#define animation_h

#include "../../../lib/opengl/opengl.h"

#include "../../data_structures/camera.h"
#include "../../data_structures/flags.h"
#include "../../data_structures/objects.h"

void prepareForHit(CueHitFlag* cueHitFlag, float* spacebarHoldTime, const float* maxPower, Ball* cueBall, Camera* camera);

void checkPockets(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize, Camera* camera);

void checkForCollisions(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize);

void ballMovement(Ball* cueBall, Ball* objectBalls, int objectBallsSize, float time);

void updateVelocity(Ball* ball, GLfloat gravity, float seconds);

void rotateCameraContinuous(RotationFlag* rotationFlag, Camera* camera, Ball* cueBall, float changeInSeconds);

void rotateCameraClockwise(Camera* camera, Ball* cueBall, float angle);

void rotateCameraCounterclockwise(Camera* camera, Ball* cueBall, float angle);

void updateCameraPosition(int* previousMoveCheck, Camera* camera, Ball* cueBall, float deltaTime);

void resetCamera(Camera* camera, Point3* newLookat);

#endif
