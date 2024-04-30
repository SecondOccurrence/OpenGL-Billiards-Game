/*
 * FILE: drawing.h
 * PURPOSE: function definitions for opengl drawing functions; the actual code for generating the vertices on the screen
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef drawing_h
#define drawing_h

#include "../math/geometry.h"

void drawObject(Object3D* obj);

void drawHouse();

void drawFloor();

void drawWalls();

void drawSquare(Point3* vertices);

void drawPyramid();

void drawTriangle(Point3* vertices);

void drawAxis();

void drawWiredGrid(const int rows, const int columns, const float length);

void drawGridSquare(Point3* vertices);

#endif
