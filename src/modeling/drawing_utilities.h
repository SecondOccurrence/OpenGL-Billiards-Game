/*
 * FILE: drawing_utilities.h
 * PURPOSE: function definitions for any general utilities to be used in drawing functions
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

void centerOfMass(Point3 c, Object3D* obj);

float calculateRadius(Object3D* obj, Point3 massCenter);

#endif
