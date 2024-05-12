/*
 * FILE: vector_operations.h
 * PURPOSE: function declarations for vector operations
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (08/05/2024): add math function to calculate unit normal
 *
 */


#include "vector_operations.h"

#include <math.h>

void multiplyByScalar(Vector3 v, GLfloat scalar) {
    v[0] = scalar * v[0];
    v[1] = scalar * v[1];
    v[2] = scalar * v[2];
}

void addVectors(Vector3 result, Vector3 v1, Vector3 v2) {
    result[0] = v1[0] + v2[0];
    result[1] = v1[1] + v2[1];
    result[2] = v1[2] + v2[2];
}

void subtractVectors(Vector3 result, Vector3 v1, Vector3 v2) {
    result[0] = v1[0] - v2[0];
    result[1] = v1[1] - v2[1];
    result[2] = v1[2] - v2[2];
}

GLfloat calcDotProduct(Vector3 v1, Vector3 v2) {
    return (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);
}

void calcCrossProduct(Vector3 result, Vector3 v1, Vector3 v2) {
    result[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    result[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
    result[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
}

float calcVecMagnitude(Vector3 v) {
    return sqrtf((v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]));
}

void normaliseVector(Vector3 v) {
    GLfloat magnitude = calcVecMagnitude(v);

    v[0] /= magnitude;
    v[1] /= magnitude;
    v[2] /= magnitude;
}

void calcUnitNormal(Vector3 result, Vector3 A, Vector3 B, Vector3 C) {
    Vector3 AB;
    subtractVectors(AB, B, A);

    Vector3 AC;
    subtractVectors(AC, C, A);

    calcCrossProduct(result, AB, AC);

    normaliseVector(result);
}
