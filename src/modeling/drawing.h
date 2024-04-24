/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for drawing 3D geometry
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
