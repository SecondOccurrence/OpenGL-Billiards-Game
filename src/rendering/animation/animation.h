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

void animate();

void checkPockets(int objectBallsSize);

void resetCamera(Camera* camera, Point3* newLookat, Point3* newPosition);

void checkForCollisions(int objectBallsSize);

void ballMovement(int objectBallsSize, float time);

void updateVelocity(Ball* ball, GLfloat gravity, float seconds);

void rotateCameraContinuous(RotationFlag* rotationFlag, float changeInSeconds);

void rotateCameraClockwise(Camera* camera, float angle);

void rotateCameraCounterclockwise(Camera* camera, float angle);

void updateCameraPosition(int* previousMoveCheck, float deltaTime);

#endif
