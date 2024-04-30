/*
 * FILE: display_functions.c
 * PURPOSE: function implementations for 3d object display.
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#include "display_functions.h"

#include "../modeling/drawing.h"
#include "../transformations/object_transformations.h"

extern int hideGrid;
extern int hideAxis;
extern int hideObjects;

void displayObject(Object3D* obj) {
    glPushMatrix();
    if(hideObjects == 0) {
        drawObject(obj);
    }
    glPopMatrix();
}

void displayAxis() {
    glPushMatrix();
    if(hideAxis == 0) {
        drawAxis();
    }
    glPopMatrix();
}

void displayGrid() {
    glPushMatrix();
    if(hideGrid == 0) {
        drawWiredGrid(8.0f, 8.0f, 2.0f);
    }
    glPopMatrix();
}
