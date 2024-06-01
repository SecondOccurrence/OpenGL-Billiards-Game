/*
 * FILE: keyboard_utils.h
 * PURPOSE: function definitions for keyboard utility functions
 *      any function which is called after a keyboard event belongs here
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): introduced mainKeys, for inputs that manipulate the core scene
 *   Contributed by Josh S, 34195182
 * - v1.2 (30/05/2024): remove unused functions
 *   Contributed by Josh S, 34195182
 *
 */

#ifndef keyboard_utils_h
#define keyboard_utils_h

#include "../data_structures/camera.h"
#include "../data_structures/flags.h"
#include "../data_structures/geometry.h"
#include "../data_structures/objects.h"

void toggleKeys(unsigned char key, AnimationFlag* animation_flag, GridFlag* grid_flag, AxisFlag* axis_flag, ObjectsFlag* objects_flag, CueHitFlag* cueHitFlag);

void cameraKeys(unsigned char key, Camera* camera, RotationFlag* rotationFlag);

void viewTop(Camera* camera);

#endif
