/*
 * FILE: gl_callback.h
 * PURPOSE: definitions for callback functions used in opengl functions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (29/05/30): add key up function
 *   Contributed by Josh S, 34195182
 *
 */

#ifndef GL_CALLBACK_H
#define GL_CALLBACK_H

void myDisplay();

void myReshape(int width, int height);

void keys(unsigned char key, int x, int y);

void keysUp(unsigned char key, int x, int y);

#endif
