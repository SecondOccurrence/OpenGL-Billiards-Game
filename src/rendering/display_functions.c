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
#include "./text.h"

#include <time.h>
#include <stdio.h>

Ball* balls = NULL;

float initialX = 2.0;
float initialZ = 0.30;

void initialiseBalls(int N) {
    balls = (Ball*)malloc(N * sizeof(Ball));
    object_balls_amount = N;
    balls = (Ball*)malloc(N * sizeof(Ball));
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        balls[i].mass = 0.5f + ((float)rand() / RAND_MAX) * 1.5f;
        balls[i].ball.radius = 0.1f;
        balls[i].ball.position[0] = 0.0f;
        balls[i].ball.position[1] = 0.0f;
        balls[i].ball.position[2] = 0.0f;
        balls[i].pocketed = 0;
    }
}

void initialiseTriangle() {
    float sphereSpacing = 0.21;

    int spheresDrawn = 0;
    int row = 1;

    while (spheresDrawn < object_balls_amount) {
        // Calculate the starting Z position for the current row
        float initialZ = -0.21 * (row - 1) / 2.0;

        for (int i = 0; i < row && spheresDrawn < object_balls_amount; i++) {
            float z = initialZ + i * sphereSpacing;
            float x = initialX + (row - 1) * sphereSpacing;

            balls[spheresDrawn].ball.position[0] = x;
            balls[spheresDrawn].ball.position[1] = balls[spheresDrawn].ball.radius;
            balls[spheresDrawn].ball.position[2] = z;

            spheresDrawn++;
        }
        row++;
    }
    glFlush();
}

void initialiseRectangle() {
    float sphereSpacing = 0.15;

    for (int i = 0; i < object_balls_amount; i++) {
        if (i % 5 == 0 && i != 0) {
            // New row, increment Z offset
            initialX += 0.15;
        }
        balls[i].ball.position[0] = initialX;
        balls[i].ball.position[1] = 0.15;
        balls[i].ball.position[2] = initialZ - (i % 5) * sphereSpacing;
    }
}

void displayBalls() {
    for (int i = 0; i < object_balls_amount; i++) {
        glPushMatrix();
        //glTranslatef(initialX, 0.15, initialZ - (i % 5) * sphereSpacing); // Translate each sphere
        glTranslatef(balls[i].ball.position[0], balls[i].ball.position[1], balls[i].ball.position[2]);
        glColor3f(1.0, 0.0, 0.0); // red color
        if(balls[i].mass < 1.0) {
            glColor3f(0.0, 1.0, 0.0);
            glutSolidSphere(balls[i].ball.radius, 20, 20);
        }
        else if((balls[i].mass >= 1.0) && (balls[i].mass <= 1.5)) {
            glColor3f(1.0, 0.0, 0.0);
            glutSolidSphere(balls[i].ball.radius, 20, 20);
        }
        else {
            glColor3f(0.0, 0.0, 1.0);
            glutSolidSphere(balls[i].ball.radius, 20, 20);
        }
        glPopMatrix();
    }
}

void displayObject(ObjectsFlag objects_flag) {
    if(objects_flag == OBJECTS_ENABLED) {
        glPushMatrix();
        glColor3f(0.8f, 0.8f, 0.8f);
        glTranslatef(cueBall.ball.position[0], cueBall.ball.position[1], cueBall.ball.position[2]);
        glutSolidSphere(cueBall.ball.radius, 10, 10);
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

void displayText() {
    GLint width = glutGet(GLUT_SCREEN_WIDTH);
    GLint height = glutGet(GLUT_SCREEN_HEIGHT);

    glPushMatrix();

        // Change to orthographic view for text
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, width, height, 0);
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
                glLoadIdentity();

                // display text elements
                text_power();
                text_remaining();

        // reset view
                glMatrixMode(GL_PROJECTION);
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        glPopMatrix();

    glPopMatrix();
}
