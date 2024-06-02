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
 * - v1.2 (13/05/2024): changed drawObject to suit changes in Object3D struct
 *   Contributed by Kaden R, 34606207
 * - v1.3 (16/05/2024): changed colour processing to suit changes with Colour type
 *   Contributed by Kaden R, 34606207
 * - v1.4 (18/05/2024): changed all Object3D* types to Object3D
 *   Contributed by Kaden R, 34606207
 * - v1.5 (20/05/2024): reverted change in v1.4
 *   Contributed by Kaden R, 34606207
 *
 */


#include "../../lib/opengl/opengl.h"

#include "drawing.h"

#include <stdio.h>

void drawObject(Object3D* obj) {
    //// draw the object
    for (int i = 0; i < obj->nfaces; i++) { // for each face in object
                                            //// draw the polygon
        glBegin(GL_POLYGON); // begin drawing polygon

        // set colour
        if (obj->hasColour) glColor3f(obj->faces[i].colour[0], obj->faces[i].colour[1], obj->faces[i].colour[2]);
        else glColor3f(1,1,1); // default for no colour
        for (int j = 0; j < obj->faces[i].vertexCount; j++) { // for each vertex of face
            int vertexNum = obj->faces[i].vertices[j];
            glVertex3fv(obj->vertices[vertexNum]); // add vertex to polygon
        }

        glEnd();

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
