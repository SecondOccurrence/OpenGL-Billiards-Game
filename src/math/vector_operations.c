/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function implementations for vector operations
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

void calcDotProduct(Vector3 result, Vector3 v1, Vector3 v2) {
    result[0] = v1[0] * v2[0];
    result[1] = v1[1] * v2[1];
    result[2] = v1[2] * v2[2];
}

void calcCrossProduct(Vector3 result, Vector3 v1, Vector3 v2) {
    result[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    result[2] = (v1[0] * v2[1]) - (v1[0] * v2[2]);
    result[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
}

float calcVecMagnitude(Vector3 v) {
    return sqrt((v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]));
}

void calcNormal(Vector3 v) {
    float magnitude = calcVecMagnitude(v);

    v[0] = v[0] / magnitude;
    v[1] = v[1] / magnitude;
    v[2] = v[2] / magnitude;
}
