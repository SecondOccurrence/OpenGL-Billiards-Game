/*
 * FILE: display_functions.h
 * PURPOSE: function definitions for 3d object display.
 *      these functions are responsible for setting up the opengl environment before drawing an object
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef display_functions_h
#define display_functions_h

#include "../math/geometry.h"

void displayObject(Object3D* obj);

void displayHouse();

void displayAxis();

void displayGrid();

#endif // display_functions_h
