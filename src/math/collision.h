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

/**
 * @brief calculates the euclidian distance between a point and a plane
 *
 * @param ballCenter - point to compare from
 * @param p1 - point 1 that exists on the plane
 * @param p2 - point 2 that exists on the plane
 * @param p3 - point 3 that exists on the plane
 * @return GLfloat
 * @post the distance between ballCenter and the plane is returned
 */
GLfloat distanceToPlane(Point3 ballCenter, Point3 p1, Point3 p2, Point3 p3);

/**
 * @brief function for checking and resolving a collision between a ball and a plane
 *
 * @param cueBall - the cue ball
 * @param collider - the plane
 * @param planeIndex - the index of the plane in the array of planes
 * @return void
 * @post if a collision has occurred, the collision is resolved
 */
void ballPlaneCollision(Ball* cueBall, PlaneProperties* collider, int planeIndex);

/**
 * @brief function for actually resolving a collision between a ball and a plane
 *
 * @param ball - the ball
 * @param distance - the distance between the ball and plane
 * @param planeNormal - the normal vector of the plane
 * @param wallIteration - the index of the plane in the array of planes
 * @return Ball
 * @post modifies the ball parameter to resolve the collision and returns the modification
 */
Ball resolveCollision(Ball* ball, GLfloat distance, Vector3 planeNormal, int wallIteration);

/**
 * @brief checks if a ball is colliding with a pocket
 *
 * @param ball - the ball
 * @param pocket - the pocket
 * @return int
 * @post returns 1 if a collision is registered
 */
int collidesWithPocket(Ball* ball, Sphere* pocket);

/**
 * @brief function for checking and resolving collision between 2 balls
 *
 * @param ball1 - the first ball
 * @param ball2 - the second ball
 * @return void
 * @post if a collision is registered, it is resolved
 */
void ballToBallCollision(Ball* ball1, Ball* ball2);

/**
 * @brief calculates the euclidian distance between two points
 *
 * @param pos1 - the first point
 * @param pos2 - the second point
 * @return GLfloat
 * @post euclidian distance between pos1 and pos2 is returned
 */
GLfloat calculateDistance(Vector3* pos1, Vector3* pos2);

/**
 * @brief adjusts 2 balls positions to be just colliding with each other
 *
 * Used before adjusting balls velocities to not cause any unexplainable behaviour
 *
 * @param ball1 - the first ball
 * @param ball2 - the second ball
 * @param penDepth - the penetration depth of ball1 with respect to ball 2
 * @param normal - the normal vector of the collision between the two balls
 * @return void
 * @post the two balls positions are adjusted to that they are colliding exactly
 */
void resolvePenetration(Ball* ball1, Ball* ball2, GLfloat penDepth, Vector3* normal);

/**
 * @brief calculates the impulse (change in momentum) when two objects have hit each other
 *
 * calculates the relative velocity of the two balls
 * multiplies the impulse magnitude with the collision normal
 * impulse magnitude is calculates by:
 *      (1 + object elasticity) * relativeVelocity
 *
 * @param impulseVector - stores the result of the calculation
 * @param ball1 - the first ball
 * @param ball2 - the second ball
 * @param collisionNormal - normal vector where the collision occurs
 * @return void
 * @post dampened impulse is returned
 */
void calculateImpulse(Vector3* impulseVector, Ball* ball1, Ball* ball2, Vector3* collisionNormal);

#endif
