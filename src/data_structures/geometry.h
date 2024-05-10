/*
 * FILE: geometry.h
 * PURPOSE: type definitions of various types of geometry used throughout the program
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef geometry_h
#define geometry_h

#include "../../lib/opengl/opengl.h"

typedef GLfloat Point2[2];
typedef GLfloat Point3[3];
typedef Point3 Vector3;
typedef GLfloat Vector4[4];
typedef int Face[3];

typedef GLfloat Matrix4[4][4];

typedef struct {
    int nvert, nfaces, nedges;
    Point3* vertices;
    Face* faces;
} Object3D;

#endif
