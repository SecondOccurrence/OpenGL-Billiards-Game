#ifndef geometry_h
#define geometry_h

#include "../../lib/opengl/opengl.h"

typedef GLfloat Point2[2];
typedef GLfloat Point3[3];
typedef Point3 Vector3;
typedef GLfloat Vector4[4];
typedef int Face[3];

typedef GLfloat Matrix4[4][4];

typedef struct Camera {
    Point3 position;
    Point3 lookat;
    Vector3 up;
} Camera;

typedef struct Object3D {
    int nvert, nfaces, nedges;
    Point3* vertices;
    Face* faces;
} Object3D;

#endif
