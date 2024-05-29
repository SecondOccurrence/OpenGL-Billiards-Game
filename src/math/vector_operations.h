/*
 * FILE: vector_operations.h
 * PURPOSE: function definitions for elementary vector operations
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef vector_operations_h
#define vector_operations_h

#include "../../lib/opengl/opengl.h"

#include "../data_structures/objects.h"
#include "../data_structures/camera.h"
#include "../data_structures/geometry.h"

void multiplyByScalar(Vector3 v, GLfloat scalar);

void addVectors(Vector3 result, Vector3 v1, Vector3 v2);

void subtractVectors(Vector3 result, Vector3 v1, Vector3 v2);

GLfloat calcDotProduct(Vector3 v1, Vector3 v2);

void calcCrossProduct(Vector3 result, Vector3 v1, Vector3 v2);

float calcVecMagnitude(Vector3 v);

void normaliseVector(Vector3 v);

void calcUnitNormal(Vector3 result, Vector3 A, Vector3 B, Vector3 C);

void calculateVelocityDirection(Vector3* endDirection, Camera* cam, CueBall* cueBall);

#endif
