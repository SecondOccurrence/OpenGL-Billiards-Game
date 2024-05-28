/*
 * FILE: matrix_operations.c
 * PURPOSE: function declarations for matrix operations
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#include "matrix_operations.h"

void multiplyByVector3(Vector4 result, Matrix4 matrixInput, Vector3 vector3Input) {
    Vector4 vector4 = {vector3Input[0], vector3Input[1], vector3Input[2], 1};

    for(int i = 0; i < 4; i++) {
        result[i] = (matrixInput[i][0] * vector4[0]) + (matrixInput[i][1] * vector4[1])
            + (matrixInput[i][2] * vector4[2]) + (matrixInput[i][3] * vector4[3]);
    }
}

void multiplyVerticesByMatrix(Point3* vertices, int vertSize, Matrix4 matrix) {
    Vector4 result;

    for(int i = 0; i < vertSize; i++) {
        multiplyByVector3(result, matrix, vertices[i]);

        vertices[i][0] = result[0];
        vertices[i][1] = result[1];
        vertices[i][2] = result[2];
    }
}
