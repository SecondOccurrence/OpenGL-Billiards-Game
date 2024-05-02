/*
 * FILE: drawing.c
 * PURPOSE: function implementations for opengl drawing functions
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
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

void drawHouse() {
    drawFloor();
    drawWalls();
    drawPyramid();
}

void drawFloor() {
    Point3 floor[4] = {{0.0, 0.0, 0.0},
                       {0.0, 0.0, 1.0},
                       {1.0, 0.0, 1.0},
                       {1.0, 0.0, 0.0}};

    glBegin(GL_POLYGON);
        glColor3f(0, 1, 0);
        glVertex3fv(floor[0]);
        glVertex3fv(floor[1]);
        glVertex3fv(floor[2]);
        glVertex3fv(floor[3]);
    glEnd();
}

void drawWalls() {
    Point3 leftWall[4] = {{0.0, 0.0, 0.0},
                          {0.0, 1.0, 0.0},
                          {0.0, 1.0, 1.0},
                          {0.0, 0.0, 1.0}};

    Point3 rightWall[4] = {{1.0, 0.0, 0.0},
                           {1.0, 1.0, 0.0},
                           {1.0, 1.0, 1.0},
                           {1.0, 0.0, 1.0}};

    Point3 backWall[4] = {{0.0, 0.0, 0.0},
                          {0.0, 1.0, 0.0},
                          {1.0, 1.0, 0.0},
                          {1.0, 0.0, 0.0}};

    drawSquare(leftWall);
    drawSquare(rightWall);
    drawSquare(backWall);


    Point3 frontWallLeft[4] = {{0.0, 0.0, 1.0},
                               {0.0, 1.0, 1.0},
                               {0.25, 1.0, 1.0},
                               {0.25, 0.0, 1.0}};

    Point3 frontWallRight[4] = {{1.0, 0.0, 1.0},
                                {1.0, 1.0, 1.0},
                                {0.75, 1.0, 1.0},
                                {0.75, 0.0, 1.0}};

    Point3 frontWallTop[4] = {{0.25, 0.75, 1.0},
                              {0.25, 1.0, 1.0},
                              {0.75, 1.0, 1.0},
                              {0.75, 0.75, 1.0}};

    drawSquare(frontWallLeft);
    drawSquare(frontWallRight);
    drawSquare(frontWallTop);
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

void drawPyramid() {
    Point3 leftTriangle[3] = {{ 0.0f,  1.0f,  0.0f},
                              { 0.0f,  1.0f,  1.0f},
                              { 0.5f,  1.5f,  0.5f}};

    Point3 rightTriangle[3] = {{ 1.0f,  1.0f,  0.0f},
                               { 1.0f,  1.0f,  1.0f},
                               { 0.5f,  1.5f,  0.5f}};

    Point3 backTriangle[3] = {{ 0.0f,  1.0f,  0.0f},
                              { 1.0f,  1.0f,  0.0f},
                              { 0.5f,  1.5f,  0.5f}};

    Point3 frontTriangle[3] = {{ 0.0f,  1.0f,  1.0f},
                               { 1.0f,  1.0f,  1.0f},
                               { 0.5f,  1.5f,  0.5f}};

    drawTriangle(leftTriangle);
    drawTriangle(rightTriangle);
    drawTriangle(backTriangle);
    drawTriangle(frontTriangle);
}

void drawTriangle(Point3* vertices) {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
        glVertex3fv(vertices[2]);
    glEnd();
}

void drawAxis() {
    Point3 vertices[4] = {{0.0, 0.0, 0.0},
                          {2.0, 0.0, 0.0},
                          {0.0, 2.0, 0.0},
                          {0.0, 0.0, 2.0}};

    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[2]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[3]);
    glEnd();
}

void drawLine(Point3 vertices[2]) {
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
    glEnd(); 
}

void drawWiredGrid(const int rows, const int columns, const float length) {
    const float lengths[2] = {(-1 * length), length};
    const float interval = (length / rows) * 2;
    float position = lengths[0];

    Point3 vertices[2];
    vertices[0][0] = lengths[0];
    vertices[0][1] = 0.0f;
    vertices[1][0] = lengths[1];
    vertices[1][1] = 0.0f;
    while(position <= length) {
        vertices[0][2] = position;
        vertices[1][2] = position;

        drawLine(vertices);

        position += interval;
    }

    position = lengths[0];
    vertices[0][2] = lengths[0];
    vertices[1][2] = lengths[1];
    while(position <= length) {
        vertices[0][0] = position;
        vertices[1][0] = position;

        drawLine(vertices);

        position += interval;
    }
}

void drawGridSquare(Point3* vertices) {
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(vertices[2]);
        glVertex3fv(vertices[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(vertices[3]);
        glVertex3fv(vertices[2]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(vertices[3]);
        glVertex3fv(vertices[0]);
    glEnd();
}
