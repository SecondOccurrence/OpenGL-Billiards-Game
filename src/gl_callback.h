/*
 * FILE: gl_callback.h
 * PURPOSE: definitions for callback functions used in opengl functions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.2 (29/05/2024): added close function as callback for glCloseFunc
 *   Contributed by Kaden R, 34606207
 *
 */

#ifndef GL_CALLBACK_H
#define GL_CALLBACK_H

/**
 * @brief callback function passed into glutDisplayFunc
 *
 * @return void
 * @post all objects are updated and displayed on the screen
 */
void myDisplay();

/**
 * @brief callback function passed into glutReshapeFunc
 *
 * @param width - width of the window
 * @param height - height of the window
 * @return void
 * @post scene is reshaped to adjust for a change in window size
 */
void myReshape(int width, int height);

/**
 * @brief callback function passed into glutKeyboardFunc
 *
 * @param key - the key pressed
 * @return void
 * @post key is checked and an action is performed if a keybind exists for it
 */
void keys(unsigned char key, int x, int y);

/**
 * @brief callback function passed into glutKeyboardUpFunc
 *
 * @param key - the key pressed
 * @return void
 * @post key is checkd and an action is performed if a keybind exists for it
 */
void upKeys(unsigned char key, int x, int y);

/**
 * @brief callback function passed into glutMouseFunc
 *
 * @param button - intger representing button clicked
 * @param state - indicated wither callback was due to release or press
 * @param x - coordinates where button state changed
 * @param y - coordinates where button state changed
 * @return void
 * @post mouse button is checked and an action is performed if a keybind exists for it
 */
void mouse(int button, int state, int x, int y);

/**
 * @brief callback function passed into glutIdleFunc
 *
 * @return void
 * @post content is called every frame, updating the scenes properties
 */
void animate(void);

#endif
