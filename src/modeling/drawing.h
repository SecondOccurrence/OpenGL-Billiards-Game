/*
 * FILE: drawing.h
 * PURPOSE: function definitions for opengl drawing functions; the actual code for generating the vertices on the screen
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed unused functions
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


#ifndef drawing_h
#define drawing_h

#include "../data_structures/geometry.h"

void drawObject(Object3D* obj);

void drawTriangle(Point3* vertices);

void drawSquare(Point3* vertices);

void drawAxis(GLfloat length);

void drawLine(Point3 p1, Point3 p2, Point3 rgb, GLfloat width);

void drawWiredGrid(const int rowsCols, const float length);

#endif
