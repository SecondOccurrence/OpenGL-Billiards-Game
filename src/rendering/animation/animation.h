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

void animate();

void ballMovement(float time);

void rotateCameraContinuous(float changeInSeconds);

void rotateCameraClockwise(Camera* camera, float angle);

void rotateCameraCounterclockwise(Camera* camera, float angle);

#endif
