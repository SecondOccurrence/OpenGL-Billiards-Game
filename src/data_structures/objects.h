#ifndef objects_h
#define objects_h

#include "geometry.h"

typedef struct {
    Vector3 position;
    GLfloat radius;
} Sphere;

typedef struct {
    Sphere ball;
    Vector3 velocity;
    GLfloat mass;
} BallProperties;

typedef struct {
    Point3 points[4];
    GLfloat bounciness;
    GLfloat friction;
} PlaneProperties;

typedef struct {
    Object3D* drawing;
    //Object3D* collision;
    /*
     * 0 - floor
     * 1 - wall found in negative z direction
     * 2 - wall found in positive x direction
     * 3 - wall found in positive z direction
     * 4 - wall found in negative x direction
     */
    PlaneProperties colliders[5];
    // insert 6 spheres for the pockets
} Shape;

#endif
