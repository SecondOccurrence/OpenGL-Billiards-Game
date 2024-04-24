/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function implementations for functions used in myDisplay found in main_functions.c/h
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
