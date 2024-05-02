/*
 * FILE: keyboard_utils.h
 * PURPOSE: function definitions for keyboard utility functions
 *      any function which is called after a keyboard event belongs here
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef keyboard_utils_h
#define keyboard_utils_h

#include "../math/geometry.h"

void keys(unsigned char key, int x, int y);

void cameraKeys(unsigned char key, int x, int y);

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

void transformKeys(unsigned char key, int x, int y, Object3D* trans);

void specialKeys(int key, int x, int y);

void rotationKeys(int key, int x, int y, Object3D* obj);

#endif
