/*
 * FILE: display_functions.c
 * PURPOSE: function implementations for 3d object display.
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed globals
 *   Contributed by Josh S, 34195182
 *
 */

#include "../../lib/opengl/opengl.h"

#include "display_functions.h"

#include "../modeling/drawing.h"

#include "../globals/objects.h"

void displayObject(ObjectsFlag objects_flag) {
    if(objects_flag == OBJECTS_ENABLED) {
        glPushMatrix();
        glColor3f(0.7 ,0.7, 0.7);
        drawSquare(planeProperties.points);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(ballProperties.position[0], ballProperties.position[1], ballProperties.position[2]);
        glutSolidSphere(ballProperties.radius, 10, 10);
        glPopMatrix();
    }
}

void displayAxis(AxisFlag axis_flag) {
    glPushMatrix();
    if(axis_flag == AXIS_ENABLED) {
        drawAxis(5.0);
    }
    glPopMatrix();
}

void displayGrid(GridFlag grid_flag) {
    glPushMatrix();
    if(grid_flag == GRID_ENABLED) {
        drawWiredGrid(30.0, 6.0);
    }
    glPopMatrix();
}
