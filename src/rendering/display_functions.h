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

/**
 * @brief object balls's parameters are assigned default values
 *
 * @param N - numberof object balls
 * @return void
 * @post object balls are initialised
 */
void initialiseBalls(int N);

/**
 * @brief assigns object balls position to be in the shape of a triangle
 *
 * @return void
 * @post object balls position are adjusted to all take the shape of a triangle
 */
void initialiseTriangle();

/**
 * @brief assigns obejct balls position to be in the shape of a rectangle
 *
 * @return void
 * @post object balls position are adjusted to all take the shape of a rectangle
 */
void initialiseRectangle();

/**
 * @brief draws a glut standard sphere for each object ball,
 *      using each object balls' properties
 *
 * @return void
 * @post all object balls are displayed on the screen
 */
void displayBalls();

// TODO: merge all display functions
/**
 * @brief displays the cue ball on the screen
 *
 * @param objects_flag - flag indicating if objects are to be rendered
 * @return void
 * @post cue ball is displayed using the global cue ball's properties
 */
void displayObject(ObjectsFlag objects_flag);

/**
 * @brief displays a custom 3D object on the screen
 *
 * @param obj - the custom 3D object to display
 * @param objects_flag - the flag indicating if objects are to be rendered
 * @return void
 * @post pool table is rendered on the screen
 */
void displayObject3D(Object3D* obj, ObjectsFlag objects_flag);

/**
 * @brief displays the axis on the screen
 *
 * @param axis_flag - flag indicating if axis should be displayed
 * @return void
 * @post displays xyz axis on the screen
 */
void displayAxis(AxisFlag axis_flag);

/**
 * @brief displays a wiregrid on the screen
 * 
 * @param grid_flag - flag indicating if grid should be displayed
 * @return void
 * @post displays a wired grid on the screen
 */ 
void displayGrid(GridFlag grid_flag);

/**
 * @brief displays text elements on the screen
 *
 * @return void
 * @post cue hit power and remaining balls text elements are displayed on the screen
 */
void displayText();

#endif
