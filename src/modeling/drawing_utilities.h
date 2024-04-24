/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Declarations for 3D object utility functions
 *
 */

#ifndef drawing_h
#define drawing_h

#include "../math/geometry.h"

void centerOfMass(Point3 c, Object3D* obj);

float calculateRadius(Object3D* obj, Point3 massCenter);

#endif
