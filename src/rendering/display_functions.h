/*
 * FILE: display_functions.h
 * PURPOSE: function definitions for 3d object display.
 *      these functions are responsible for setting up the opengl environment before drawing an object
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (10/05/2024): removed globals
 *   Contributed by Josh S, 34195182
 * - v1.2 (13/05/2024): added function to display an Object3D object
 *   Contributed by Kaden R, 34606207
 *
 */


#ifndef display_functions_h
#define display_functions_h

#include "../data_structures/flags.h"
#include "../data_structures/geometry.h"

void displayObject(ObjectsFlag objects_flag);

void displayObject3D(Object3D* obj, ObjectsFlag objects_flag);

void displayAxis(AxisFlag axis_flag);

void displayGrid(GridFlag grid_flag);

#endif
