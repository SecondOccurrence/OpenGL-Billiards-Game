/*
 * FILE: gl_callback.c
 * PURPOSE: callback functions used in opengl functions.
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */

#include "../lib/opengl/opengl.h"

#include "math/geometry.h"
#include "rendering/display_functions.h"
#include "movement/keyboard_utils.h"

enum cameraMode;

extern Camera camera;

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camera.position[0], camera.position[1], camera.position[2],
              camera.lookat[0], camera.lookat[1], camera.lookat[2],
              camera.up[0], camera.up[1], camera.up[2]);

    displayAxis();
    displayGrid();

    glFlush();
}

void myReshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(height == 0) {
        height = 1.0;
    }
    if(width == 0) {
        width = 1.0;
    }

    if(cameraMode == ORTHO) {
        GLdouble left = -2;
        GLdouble right = 2;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;     // near and far clipping planes

        if(width <= height) {
            GLfloat aspect = (GLfloat) height / (GLfloat) width;
            glOrtho(left, right, bottom * aspect, top * aspect, nearVal,  farVal);
        }
        else {
            GLfloat aspect = (GLfloat) width / (GLfloat) height;
            glOrtho(left * aspect, right * aspect, bottom, top, nearVal, farVal);
        }

    }
    else if(cameraMode == PERSPECTIVE) {
        GLdouble fov = 60;
        GLdouble aspect = 1.0 * width / height;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        gluPerspective(fov, aspect, nearVal, farVal);

    }
    else if(cameraMode == FRUSTUM) {
        GLdouble left = -1;
        GLdouble right= 1;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.05;
        GLdouble farVal = 100;
        glFrustum(left, right, bottom, top, nearVal, farVal);
    }

    glMatrixMode(GL_MODELVIEW);
}

void keys(unsigned char key, int x, int y) {
    // TODO: refactor
    switch(key) {
    case 'Q':
    case 'q':
        exit(0);
        break;
    case 'G':
    case 'g':
        hideGrid ^= 1;
        break;
    case 'O':
    case 'o':
        hideAxis ^= 1;
        break;
    case 'L':
    case 'l':
        hideObjects ^= 1;
        break;
    }

    cameraKeys(key, x, y);

    //transformKeys(key, x, y);

    glutPostRedisplay();
}
