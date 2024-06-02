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

/**
 * @brief draws a custom 3D object to the screen
 *
 * @param obj - the object to draw
 * @return void
 * @pre obj has allocated memory and has valid data
 * @post the objects vertices and faces data are displayed on the screen, creating an object
 */
void drawObject(Object3D* obj);

/**
 * @brief draws a triangle to the screen
 *
 * @param vertices - the triangle vertices. contains 3 Point3s
 * @return void
 * @pre vertices has 3x Point3s
 * @post a triangle is drawn on the screen
 */
void drawTriangle(Point3* vertices);

/**
 * @brief draws a square to the screen
 *
 * @param vertices - the square vertices. contains 4 Point3s
 * @return void
 * @pre vertices has 4x Point3s
 * @post a square is drawn on the screen
 */
void drawSquare(Point3* vertices);

/**
 * @brief lines representing the x,y,z axis are drawn to the screen
 *
 * @param length - the length of the axis line
 * @return void
 * @post xyz axis is displayed on the screen
 */
void drawAxis(GLfloat length);

/**
 * @brief draws a line on the screen from 1 point toanother
 *
 * @param p1 - start of the line
 * @param p2 - end of the line
 * @param rgb - Point3 representing rgb values on a scale of 0-1.0f
 * @param width - the line width
 * @return void
 * @post a line is drawn from p1 to p2
 */
void drawLine(Point3 p1, Point3 p2, Point3 rgb, GLfloat width);

/**
 * @brief a wired grid is drawn expanding from the origin
 *
 * @param rowsCols - amount of rows and columns to draw
 * @param length - how big the grid will be
 * @return void
 * @post a wired grid is drawn
 */
void drawWiredGrid(const int rowsCols, const float length);

#endif
