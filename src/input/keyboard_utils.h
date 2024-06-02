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

/**
 * @brief keybinds related to toggling on/off flags
 *
 * @param key - the key pressed
 * @param animation_flag - the animation flag
 * @param grid_flag - the grid flag
 * @param axis_flag - the axis flag
 * @param objects_flag - the objects flag
 * @param cueHitFlag - the cue hit flag
 * @return void
 */
void toggleKeys(unsigned char key, AnimationFlag* animation_flag, GridFlag* grid_flag, AxisFlag* axis_flag, ObjectsFlag* objects_flag, CueHitFlag* cueHitFlag);

/**
 * @brief keybinds related to camera operations
 *
 * @param key - the key pressed
 * @param camera - the camera
 * @param rotationFlag - the rotation flag
 * @return void
 */
void cameraDownKeys(unsigned char key, Camera* camera, RotationFlag* rotationFlag);

/**
 * @brief keybinds related to camera operations: called only when a key is released
 *
 * @param key - the key pressed
 * @param rotationFlag - the rotationFlag
 * @return void
 */
void cameraUpKeys(unsigned char key, RotationFlag* rotationFlag);

/**
 * @brief sets the camera to look top-down at the origin
 *
 * @param camera - the camera
 * @return
 */
void viewTop(Camera* camera);

/**
 * @brief general keybinds: only called on key release
 *
 * @param key - the key pressed
 * @param spacebarPressFlag - flag indicating if the spacebar is pressed
 * @return void
 */
void toggleUpKeys(unsigned char key, int* spacebarPressFlag);

/**
 * @brief mouse click bindings
 *
 * @param button - integer representing the mouse button pressed
 * @param cueHitFlag - the cue hit flag
 * @return void
 */
void toggleMouse(int button, CueHitFlag* cueHitFlag);


/**
 * @brief mouse bindings: only called on mouse click release. Currently unused but implemented for future updates.
 *
 * @param button - integer representing the mouse button released
 * @return void
 */
 void toggleUpMouse(int button);

#endif
