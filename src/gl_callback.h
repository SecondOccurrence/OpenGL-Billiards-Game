/*
 * FILE: gl_callback.h
 * PURPOSE: definitions for callback functions used in opengl functions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
<<<<<<< HEAD
 * - v1.1 (29/05/30): add key up function
 *   Contributed by Josh S, 34195182
=======
 * - v1.1 (29/05/2024): added close function as callback for glCloseFunc
 *   Contributed by Kaden R, 34606207
>>>>>>> 7c05b6a (Memory for table shape now frees upon close)
 *
 */

#ifndef GL_CALLBACK_H
#define GL_CALLBACK_H

void myDisplay();

void myReshape(int width, int height);

void keys(unsigned char key, int x, int y);
void upKeys(unsigned char key, int x, int y);

void mouse(int button, int state, int x, int y);

#endif
