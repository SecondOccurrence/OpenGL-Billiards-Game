/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for matrix operations
 *
 */

#ifndef matrix_operations_h
#define matrix_operations_h

#include "../../lib/opengl/opengl.h"

#include "geometry.h"

void multiplyByVector3(Vector4 result, Matrix4 matrixInput, Vector3 vector3Input);

void multiplyVerticesByMatrix(Point3* vertices, int vertSize, Matrix4 matrix);

#endif
