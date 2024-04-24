/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for opengl keyboard utilities
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
