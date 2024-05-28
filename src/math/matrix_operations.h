/*
 * FILE: matrix_operations.h
 * PURPOSE: function definitions for simple matrix operations
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef matrix_operations_h
#define matrix_operations_h

#include "../../lib/opengl/opengl.h"

#include "../data_structures/geometry.h"

void multiplyByVector3(Vector4 result, Matrix4 matrixInput, Vector3 vector3Input);

void multiplyVerticesByMatrix(Point3* vertices, int vertSize, Matrix4 matrix);

#endif
