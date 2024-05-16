/*
 * FILE: geometry.h
 * PURPOSE: type definitions of various types of geometry used throughout the program
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (12/05/2024): added properties for faces to store more than 3 vertices per face and store colours for its faces
 *   Contributed by Kaden R, 34606207
 * - v1.2 (16/05/2024): changed type of Colour from struct to GLfloat array
 *   Contributed by Kaden R, 34606207
 *
 */


#ifndef geometry_h
#define geometry_h

#define MAX_FACE_VERTICES 5

#include "../../lib/opengl/opengl.h"
#include <stdbool.h>

typedef GLfloat Point2[2];
typedef GLfloat Point3[3];
typedef Point3 Vector3;
typedef GLfloat Vector4[4];
typedef GLfloat Matrix4[4][4];

typedef GLfloat Colour[3];

typedef struct {
    int vertexCount;                  // number of vertices
    int vertices[MAX_FACE_VERTICES];  // the vertices
    Colour colour;                    // colour of the face
} Face;

typedef struct {
    int nvert, nfaces, nedges;
    bool hasColour; // true if object has associated RGB values. Affects how OFF file is read and how object is rendered
    Point3* vertices;
    Face* faces;
} Object3D;

#endif
