#ifndef objects_h
#define objects_h

#include "geometry.h"

typedef struct BallProperties {
    Vector3 position;
    Vector3 velocity;
    GLfloat mass;
    GLfloat radius;
} BallProperties;

typedef struct PlaneProperties {
    Point3 points[4];
    GLfloat bounciness;
    GLfloat friction;
} PlaneProperties;

#endif
