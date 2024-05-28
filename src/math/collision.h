/*
 * FILE: collision.h
 * PURPOSE: function declarations for collision calculations
 * DATE: 06/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (06/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (08/05/2024): added collision resolution to this file.
 *      removed collision check function. now done in the animation file
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef collision_h
#define collision_h

#include "../../lib/opengl/opengl.h"

#include "../data_structures/objects.h"

#include "../data_structures/geometry.h"

GLfloat distanceToPlane(Point3 ballCenter, Point3 p1, Point3 p2, Point3 p3);

BallProperties resolveCollision(BallProperties* ball, GLfloat distance, Vector3 planeNormal);

#endif
