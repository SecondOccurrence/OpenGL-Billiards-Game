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
 *
 */

#ifndef keyboard_utils_h
#define keyboard_utils_h

#include "../math/geometry.h"

void mainKeys(unsigned char key);

void cameraKeys(unsigned char key);

void strafeLeft();

void strafeRight();

void moveForward();

void moveBackward();

void viewFront();

void viewRear();

void viewTop();

void viewBottom();

void viewRight();

void viewLeft();

void transformKeys(unsigned char key, Object3D* trans);

void specialKeys(int key, int x, int y);

void rotationKeys(int key, Object3D* obj);

#endif
