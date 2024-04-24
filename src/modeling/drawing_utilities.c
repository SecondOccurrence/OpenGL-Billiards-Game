/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Implementations for 3D object utility functions
 *
 */

#include "drawing_utilities.h"

#include "../math/vector_operations.h"

#include <math.h>

void centerOfMass(Point3 c, Object3D* obj) {
    int nVertices = obj->nvert;
    Point3 sums = {0.0, 0.0, 0.0};

    for(int i = 0; i < nVertices; i++) {
        sums[0] += obj->vertices[i][0];
        sums[1] += obj->vertices[i][1];
        sums[2] += obj->vertices[i][2];
    }

    c[0] = sums[0] / nVertices;
    c[1] = sums[1] / nVertices;
    c[2] = sums[2] / nVertices;
}

float calculateRadius(Object3D* obj, Point3 massCenter) {
    int SIZE = obj->nvert;

    Vector3 v;
    float magnitude = 0.0;
    float maxMagnitude = magnitude;
    for(int i = 0; i < SIZE; i++) {
        subtractVectors(v, obj->vertices[i], massCenter);
        magnitude = calcVecMagnitude(v);
        if(magnitude > maxMagnitude) {
            maxMagnitude = magnitude;
        }
    }

    return magnitude;
}
