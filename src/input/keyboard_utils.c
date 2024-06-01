/*
 * FILE: keyboard_utils.c
 * PURPOSE: function implementation for keyboard utility functions
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): introduced mainKeys, for inputs that manipulate the core scene. also clean up of unused parameters
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed globals
 *   Contributed by Josh S, 34195182
 * - v1.2 (12/05/2024): added keys to alter ball velocity
 *   Contributed by Josh S, 34195182
 * - v1.3 (29/05/2024): escape key (key 27) now leaves main loop instead of exits
 *   Contributed by Kaden R, 34606207
 * - v1.4 (30/05/2024): remove unused functions
 *   Contributed by Josh S, 34195182
 *
 */

#include "keyboard_utils.h"

#include "../math/vector_operations.h"
#include "../globals/general.h"

#include <stdio.h>

void toggleKeys(unsigned char key, AnimationFlag* animation_flag, GridFlag* grid_flag, AxisFlag* axis_flag, ObjectsFlag* objects_flag, int* spacebarPressFlag) {
    switch(key) {
    case 'P':
    case 'p':
        if(*animation_flag == ANIMATION_ENABLED) {
            *animation_flag = ANIMATION_DISABLED;
        }
        else {
            *animation_flag = ANIMATION_ENABLED;
        }
        break;
    case 'G':
    case 'g':
        if(*grid_flag == GRID_ENABLED) {
            *grid_flag = GRID_DISABLED;
        }
        else {
            *grid_flag = GRID_ENABLED;
        }
        break;
    case 'O':
    case 'o':
        if(*axis_flag == AXIS_ENABLED) {
            *axis_flag = AXIS_DISABLED;
        }
        else {
            *axis_flag = AXIS_ENABLED;
        }
        break;
    case 'L':
    case 'l':
        if(*objects_flag == OBJECTS_ENABLED) {
            *objects_flag = OBJECTS_DISABLED;
        }
        else {
            *objects_flag = OBJECTS_ENABLED;
        }
        break;
    case ' ':
        *spacebarPressFlag = 1;
        break;
    case 27:
        glutLeaveMainLoop();
        break;
    default:
        break;
    }
}

void cameraDownKeys(unsigned char key, Camera* camera, RotationFlag* rotationFlag) {
    switch(key) {
    case 'T':
    case 't':
        viewTop(camera);
        break;
    case 'A':
    case 'a':
        *rotationFlag = ROTATION_ANTICLOCKWISE;
        break;
    case 'D':
    case 'd':
        *rotationFlag = ROTATION_CLOCKWISE;
        break;
    default:
        break;
    }
}
void cameraUpKeys(unsigned char key, Camera* camera, RotationFlag* rotationFlag) {
    switch(key) {
    case 'A':
    case 'a':
    case 'D':
    case 'd':
        *rotationFlag == ROTATION_DISABLED;
        *rotationFlag = ROTATION_DISABLED;
        break;
    default:
        break;
    }
}

void viewTop(Camera* camera) {
    Point3 newPosition = {0.0f, 5.0f, 0.0f};
    Point3 newLookat = {0.0f, 0.0f, 0.0f};
    Point3 newUp = {0.0f, 0.0f, 1.0f};

    for(int i = 0; i < 3; i++) {
        camera->position[i] = newPosition[i];
        camera->lookat[i] = newLookat[i];
    }

    if(camera->up[1] != 0.0f) {
        camera->up[0] = newUp[0];
        camera->up[1] = newUp[1];
        camera->up[2] = newUp[2];
    }
}


void toggleUpKeys(unsigned char key, int* spacebarPressFlag) {
    switch(key) {
    case ' ':
        *spacebarPressFlag = 0;
        break;
    }
}
