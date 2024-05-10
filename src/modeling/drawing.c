/*
 * FILE: drawing.c
 * PURPOSE: function implementations for opengl drawing functions
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed unused functions and refactor functions
 *   Contributed by Josh S, 34195182
 *
 */


#include "../../lib/opengl/opengl.h"

#include "drawing.h"

#include <stdio.h>

void drawObject(Object3D* obj) {
    int facesSize = obj->nfaces;

    Face currentFace;
    Point3 triVertices[3];
    for(int i = 0; i < facesSize; i++) {
        currentFace[0] = obj->faces[i][0];
        currentFace[1] = obj->faces[i][1];
        currentFace[2] = obj->faces[i][2];

        triVertices[0][0] = obj->vertices[currentFace[0]][0];
        triVertices[0][1] = obj->vertices[currentFace[0]][1];
        triVertices[0][2] = obj->vertices[currentFace[0]][2];

        triVertices[1][0] = obj->vertices[currentFace[1]][0];
        triVertices[1][1] = obj->vertices[currentFace[1]][1];
        triVertices[1][2] = obj->vertices[currentFace[1]][2];

        triVertices[2][0] = obj->vertices[currentFace[2]][0];
        triVertices[2][1] = obj->vertices[currentFace[2]][1];
        triVertices[2][2] = obj->vertices[currentFace[2]][2];

        drawTriangle(triVertices);
    }
}

void drawTriangle(Point3* vertices) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glEnd();
}

void drawSquare(Point3* vertices) {
    glBegin(GL_POLYGON);
        glColor3f(0, 1, 1);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
        glVertex3fv(vertices[2]);
        glVertex3fv(vertices[3]);
    glEnd();
}

void drawAxis(GLfloat length) {
    Point3 vertices[4] = {{0.0   , 0.0   , 0.0   },
                          {length, 0.0   , 0.0   },
                          {0.0   , length, 0.0   },
                          {0.0   , 0.0   , length}};

    Point3 rgb = {1.0f, 0.0f, 0.0f};
    drawLine(vertices[0], vertices[1], rgb, 3.0f);
    rgb[0] = 0.0f;
    rgb[1] = 1.0f;
    drawLine(vertices[0], vertices[2], rgb, 3.0f);
    rgb[1] = 0.0f;
    rgb[2] = 1.0f;
    drawLine(vertices[0], vertices[3], rgb, 3.0f);
}

void drawLine(Point3 p1, Point3 p2, Point3 rgb, GLfloat width) {
    glLineWidth(width);
    glBegin(GL_LINES);
        glColor3fv(rgb);
        glVertex3fv(p1);
        glVertex3fv(p2);
    glEnd(); 
}

void drawWiredGrid(const int rowsCols, const float length) {
    Point3 rgb = {1.0f, 1.0f, 1.0f};
    const float lengths[2] = {(-1 * length), length};
    const float interval = (length / rowsCols) * 2;
    float position = lengths[0];

    Point3 vertices[2];
    vertices[0][0] = lengths[0];
    vertices[0][1] = 0.0f;
    vertices[1][0] = lengths[1];
    vertices[1][1] = 0.0f;
    while(position <= length) {
        vertices[0][2] = position;
        vertices[1][2] = position;

        drawLine(vertices[0], vertices[1], rgb, 1.0f);

        position += interval;
    }

    position = lengths[0];
    vertices[0][2] = lengths[0];
    vertices[1][2] = lengths[1];
    while(position <= length) {
        vertices[0][0] = position;
        vertices[1][0] = position;

        drawLine(vertices[0], vertices[1], rgb, 1.0f);

        position += interval;
    }
}
