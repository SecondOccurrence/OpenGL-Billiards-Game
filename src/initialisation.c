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
 * - v1.1 (14/05/2024): Set Camera position to ball position and adding Sphere flag
 *   Contributed by Abhijeet S, 34777306
 */

#include "../lib/opengl/opengl.h"

#include "initialisation.h"

#include "math/vector_operations.h"
#include "rendering/display_functions.h"
#include "modeling/drawing.h"
#include "modeling/object_loading.h"
#include "input/user_input.h"
#include "rendering/animation/animation.h"

#include "globals/camera.h"
#include "globals/objects.h"
#include "globals/flags.h"
#include "globals/general.h"

Camera camera;
Point3 potentialCameraPosition = {0.0f, 0.0f, 0.0f};

Shape table = {
    NULL,
    // colliders
    {{{{-4.0, 0.0, -2.0},
       { 4.0, 0.0, -2.0},
       {-4.0, 0.0,  2.0},
       { 4.0, 0.0, -2.0}}, 0.9, 0.9}, // floor

     {{{-4.0, 0.2, -2.0},
       { 4.0, 0.2, -2.0},
       {-4.0, 0.0, -2.0},
       { 4.0, 0.0, -2.0}}, 0.9, 0.9}, // -z

     {{{ 4.0, 0.2, -2.0},
       { 4.0, 0.2,  2.0},
       { 4.0, 0.0, -2.0},
       { 4.0, 0.0,  2.0}}, 0.9, 0.9}, // +x

     {{{-4.0, 0.2, 2.0},
       { 4.0, 0.2, 2.0},
       {-4.0, 0.0, 2.0},
       { 4.0, 0.0, 2.0}}, 0.9, 0.9}, // +z

     {{{-4.0, 0.2, -2.0},
       {-4.0, 0.2,  2.0},
       {-4.0, 0.0, -2.0},
       {-4.0, 0.0,  2.0}}, 0.9, 0.9}}, // -x

    // pockets
    {{{-4.0f, 0.0f, -2.0f}, 0.2},
     {{ 0.0f, 0.0f, -2.0f}, 0.2},
     {{ 4.0f, 0.0f, -2.0f}, 0.2},
     {{-4.0f, 0.0f,  2.0f}, 0.2},
     {{ 0.0f, 0.0f,  2.0f}, 0.2},
     {{ 4.0f, 0.0f,  2.0f}, 0.2}}
};

Ball cueBall = {
   {{-2.5, 0.1, 0.0}, 0.1},
    {0.0, 0.0, 0.0},
    1.0f
};

PlaneProperties planeProperties = {
    {{-5.0, 0.0, -5.0},
     { 5.0, 0.0, -5.0},
     { 5.0, 0.0,  5.0},
     {-5.0, 0.0,  5.0}},
    0.8, 0.9
};

AnimationFlag animation_flag = ANIMATION_ENABLED;
GridFlag grid_flag = GRID_ENABLED;
AxisFlag axis_flag = AXIS_ENABLED;
ObjectsFlag objects_flag = OBJECTS_ENABLED;
ObjectBallsShape object_balls_shape = TRIANGLE;

RotationFlag rotation_flag_c = ROTATION_DISABLED;
RotationFlag rotation_flag_a = ROTATION_DISABLED;

int spacebarPressed = 0;
float spacebarHoldTime = 0.0f;
int previousMoveCheck = 0;

int object_balls_amount = 0;

void init() {
    table.drawing = readOFFFile("../public/3D-data/Table_Coloured.off");

    setLight();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);

    Point3 cameraPosition = {-4.0f, 0.5f, 0.0f};
    Point3 upVec = {0.0f, 1.0f, 0.0f};
    for(int i = 0; i < 3; i++) {
        camera.position[i] = cameraPosition[i];
        camera.lookat[i] = cueBall.ball.position[i];
        camera.up[i] = upVec[i];

        potentialCameraPosition[i] = cameraPosition[i];
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    camera.cameraMode= PERSPECTIVE;
    setCamera(camera.cameraMode);

    previousFrameTime = glutGet(GLUT_ELAPSED_TIME);
    glutIdleFunc(animate);
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
