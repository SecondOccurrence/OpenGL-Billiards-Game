/*
 * FILE: initialisation.c
 * PURPOSE: contains functions that are used exclusively in the main (main.c) file.
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): extracting opengl callback functiong, leaving only intialisation functions
 *      renamed file from main_functions to intialisation
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): restructured globals
 *   Contributed by Josh S, 34195182
 *
 */

#include "../lib/opengl/opengl.h"

#include "initialisation.h"

#include "math/vector_operations.h"
#include "rendering/display_functions.h"
#include "modeling/drawing.h"
#include "modeling/object_loading.h"

#include "globals/camera.h"
#include "globals/objects.h"
#include "globals/flags.h"

Camera camera;

Shape table;

BallProperties ballProperties = {
    {0.5, 1.0, 0.0},
    {0.0, 0.0, 0.0},
    1.0f, 0.1};
PlaneProperties planeProperties = {
    {{-5.0, 0.0, -5.0},
     { 5.0, 0.0, -5.0},
     { 5.0, 0.0,  5.0},
     {-5.0, 0.0,  5.0}},
    0.8, 0.9
};

AnimationFlag animation_flag = ANIMATION_DISABLED;
GridFlag grid_flag = GRID_ENABLED;
AxisFlag axis_flag = AXIS_ENABLED;
ObjectsFlag objects_flag = OBJECTS_ENABLED;

void init() { 
    table.collision = readOFFFile("../public/3D-data/Table Collision_Simplified.off");
    table.drawing   = readOFFFile("../public/3D-data/Table_Coloured.off");

    setLight();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);

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

    camera.cameraMode= PERSPECTIVE;
    setCamera(camera.cameraMode);
}

void setLight(void){
    GLfloat  mat_specular[]  =  {1.0, 1.0, 1.0, 1.0 };

    GLfloat  mat_shininess[] =  {50.0};

    GLfloat  light_position[] =  {1.0, 1.0, 2.0, 0.0 };
    GLfloat  lmodel_ambient[] =  {0.7, 0.7, 0.7, 1.0};

    glLightfv (GL_LIGHT0, GL_POSITION, light_position);

    glLightModelfv (GL_LIGHT_MODEL_AMBIENT,  lmodel_ambient);

    glMaterialfv (GL_FRONT, GL_SPECULAR,   mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS,  mat_shininess);

    glEnable(GL_COLOR_MATERIAL);

    glEnable (GL_LIGHTING);

    glEnable (GL_LIGHT0);

    glEnable (GL_DEPTH_TEST);
}

void setCamera(int mode) {
    if(mode == ORTHO2D) {
        gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    }
    else if(mode == ORTHO) {
        GLdouble left = -2;
        GLdouble right = 2;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        glOrtho(left, right, bottom, top, nearVal, farVal);
    }
    else if(mode == PERSPECTIVE) {
        GLdouble fov = 60;
        GLdouble aspect = 1;
        GLdouble nearVal = 0.1;
        GLdouble farVal = 100;

        gluPerspective(fov, aspect, nearVal, farVal);
    }
    else if(mode == FRUSTUM) {
        GLdouble left = -1;
        GLdouble right = 1;
        GLdouble bottom = -1;
        GLdouble top = 1;
        GLdouble nearVal = 0.05;
        GLdouble farVal = 100;

        glFrustum(left, right, bottom, top, nearVal, farVal);
    }
}