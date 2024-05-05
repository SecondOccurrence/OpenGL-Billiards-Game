/*
 * FILE: initialisation.h
 * PURPOSE: function definitions for functions used in the main program file
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): extracting opengl callback functiong, leaving only intialisation functions
 *      renamed file from main_functions to intialisation
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef initialisation_h
#define initialisation_h

#include "math/geometry.h"

void init();

void setLight(void);

void setCamera(int cameraMode);

#endif
