/*
 * FILE: gl_callback.c
 * PURPOSE: callback functions used in opengl functions.
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): restructured globals
 *   Contributed by Josh S, 34195182
 * - v1.1 (14/05/2024): changing gluLookAt
 *   Contributed by Abhijeet S, 34777306
 * - v1.2 (29/05/2024): added close function as callback for glCloseFunc
 *   Contributed by Kaden R, 34606207
 */

#include "../lib/opengl/opengl.h"

#include "data_structures/geometry.h"
#include "rendering/display_functions.h"
#include "input/keyboard_utils.h"
#include "modeling/object_loading.h"

#include "globals/camera.h"
#include "globals/flags.h"
#include "globals/objects.h"

extern Shape table;

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camera.position[0], camera.position[1], camera.position[2],
              camera.lookat[0], camera.lookat[1], camera.lookat[2],
              camera.up[0], camera.up[1], camera.up[2]);

    displayObject(objects_flag);
    displayObject3D(table.drawing, objects_flag);
    displayAxis(axis_flag);
    displayGrid(grid_flag);

    if(object_balls_shape == TRIANGLE) {
        displayTriangle();
    }
    else {
        displayRectangle();
    }

    glutSwapBuffers();
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

    if(camera.cameraMode == ORTHO) {
        GLdouble left = -2;
        GLdouble right = 2;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        if(width <= height) {
            GLfloat aspect = (GLfloat) height / (GLfloat) width;
            glOrtho(left, right, bottom * aspect, top * aspect, nearVal,  farVal);
        }
        else {
            GLfloat aspect = (GLfloat) width / (GLfloat) height;
            glOrtho(left * aspect, right * aspect, bottom, top, nearVal, farVal);
        }

    }
    else if(camera.cameraMode == PERSPECTIVE) {
        GLdouble fov = 80;
        GLdouble aspect = 1.0 * width / height;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        gluPerspective(fov, aspect, nearVal, farVal);

    }
    else if(camera.cameraMode == FRUSTUM) {
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
    toggleKeys(key, &animation_flag, &grid_flag, &axis_flag, &objects_flag, &spacebarPressed);

    cameraKeys(key, &camera, &rotation_flag_a, &rotation_flag_c);

    glutPostRedisplay();
}
