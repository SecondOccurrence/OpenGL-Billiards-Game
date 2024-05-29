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
 * - v1.2 (13/05/2024): added function to display an Object3D object
 *   Contributed by Kaden R, 34606207
 * - v1.3 (18/05/2024): changed all Object3D* types to Object3D
 *   Contributed by Kaden R, 34606207
 * - v1.4 (20/05/2024): reverted v1.3
 *   Contributed by Kaden R, 34606207
 *
 */

#include "../../lib/opengl/opengl.h"

#include "display_functions.h"

#include "../modeling/drawing.h"

#include "../globals/objects.h"
#include "../globals/general.h"

void displayTriangle() {
    float sphereSpacing = 0.15; // Spacing between spheres
    float initialX = 2.0;       // Initial x position for the first sphere

    int spheresDrawn = 0;
    int row = 1;

    while (spheresDrawn < object_balls_amount) {
        // Calculate the starting Z position for the current row
        float initialZ = -0.15 * (row - 1) / 2.0;

        for (int i = 0; i < row && spheresDrawn < object_balls_amount; i++) {
            float z = initialZ + i * sphereSpacing;
            float x = initialX + (row - 1) * sphereSpacing; // Adjusted x position

            glPushMatrix();
            glTranslatef(x, 0.15, z); // Translate each sphere
            glColor3f(1.0, 0.0, 0.0); // Red color
            glutSolidSphere(0.1, 20, 20); // Draw a solid sphere
            glPopMatrix();

            spheresDrawn++;
        }
        row++;
    }
    glFlush();
}

void displayRectangle() {
    // Initial positions for the first sphere
    float initialX = 2.0;
    float initialZ = 0.30;
    // Draw multiple solid spheres

    float sphereSpacing = 0.15; // Spacing between spheres

    for (int i = 0; i < object_balls_amount; i++) {
        if (i % 5 == 0 && i != 0) {
            // New row, increment Z offset
            initialX += 0.15;
        }

        glPushMatrix();
        glTranslatef(initialX, 0.15, initialZ - (i % 5) * sphereSpacing); // Translate each sphere
        glColor3f(1.0, 0.0, 0.0); // red color
        glutSolidSphere(0.1, 20, 20); // draw a solid sphere
        glPopMatrix();
    }
    glFlush();
}

void displayObject(ObjectsFlag objects_flag) {
    if(objects_flag == OBJECTS_ENABLED) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(ballProperties.ball.position[0], ballProperties.ball.position[1], ballProperties.ball.position[2]);
        glutSolidSphere(ballProperties.ball.radius, 10, 10);
        glPopMatrix();
    }
}

void displayObject3D(Object3D* obj, ObjectsFlag objects_flag) {
    if(objects_flag == OBJECTS_ENABLED) {
        drawObject(obj);
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
