/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for vector operations
 *
 */

#ifndef vector_operations_h
#define vector_operations_h

#include "../../lib/opengl/opengl.h"

#include "geometry.h"

void multiplyByScalar(Vector3 v, GLfloat scalar);

void addVectors(Vector3 result, Vector3 v1, Vector3 v2);

void subtractVectors(Vector3 result, Vector3 v1, Vector3 v2);

void calcDotProduct(Vector3 result, Vector3 v1, Vector3 v2);

void calcCrossProduct(Vector3 result, Vector3 v1, Vector3 v2);

float calcVecMagnitude(Vector3 v);

void calcNormal(Vector3 v);

#endif
