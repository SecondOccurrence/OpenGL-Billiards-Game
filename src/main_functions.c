/*
 * FILE: main_functions.c
 * PURPOSE: contains functions that are used exclusively in the main (main.c) file.
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */

#include "../lib/opengl/opengl.h"

#include "main_functions.h"

#include "math/geometry.h"
#include "math/vector_operations.h"
#include "rendering/display_functions.h"
#include "modeling/drawing.h"

#include <stdio.h>

enum {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
} cameraMode = PERSPECTIVE;

Camera camera;

extern Object3D bone;

void init(void) { 
    setLight();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);

    camera.position[0] = 1.f;
    camera.position[1] = 1.1f;
    camera.position[2] = 2.f;

    camera.lookat[0] = 0.f;
    camera.lookat[1] = 0.f;
    camera.lookat[2] = 0.f;

    camera.up[0] = 0.f;
    camera.up[1] = 1.f;
    camera.up[2] = 0.f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    cameraMode = PERSPECTIVE;
    setCamera(cameraMode);
}

void setLight(void){
    GLfloat  mat_specular[]  =  {1.0, 1.0, 1.0, 1.0 };

    GLfloat  mat_shininess[] =  {50.0};

    GLfloat  light_position[] =  {1.0, 1.0, 2.0, 0.0 };
    GLfloat  lmodel_ambient[] =  {0.2, 0.2, 0.2, 1.0};

    glLightfv (GL_LIGHT0, GL_POSITION, light_position);

    glLightModelfv (GL_LIGHT_MODEL_AMBIENT,  lmodel_ambient);

    glMaterialfv (GL_FRONT, GL_SPECULAR,   mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS,  mat_shininess);

    glEnable(GL_COLOR_MATERIAL);

    glEnable (GL_LIGHTING);

    glEnable (GL_LIGHT0);

    glEnable (GL_DEPTH_TEST);
}

void setCamera(int cameraMode) {
    if(cameraMode == ORTHO2D) {
        gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    }
    else if(cameraMode == ORTHO) {
        GLdouble left = -2;
        GLdouble right = 2;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        glOrtho(left, right, bottom, top, nearVal, farVal);
    }
    else if(cameraMode == PERSPECTIVE) {
        GLdouble fov = 60;
        GLdouble aspect = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        gluPerspective(fov, aspect, nearVal, farVal);
    }
    else if(cameraMode == FRUSTUM) {
        GLdouble left = -1;
        GLdouble right = 1;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.05;
        GLdouble farVal = 100;

        glFrustum(left, right, bottom, top, nearVal, farVal);
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camera.position[0], camera.position[1], camera.position[2],
              camera.lookat[0], camera.lookat[1], camera.lookat[2],
              camera.up[0], camera.up[1], camera.up[2]);

    displayObject(&bone);

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
