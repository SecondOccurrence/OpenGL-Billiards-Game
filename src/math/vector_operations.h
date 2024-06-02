/*
 * FILE: vector_operations.h
 * PURPOSE: function definitions for elementary vector operations
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */

#ifndef vector_operations_h
#define vector_operations_h

#include "../../lib/opengl/opengl.h"

#include "../data_structures/objects.h"
#include "../data_structures/camera.h"
#include "../data_structures/geometry.h"

/**
 * @brief multiplies a vector by a scalar
 *
 * @param result - vector to store the result of the calculation
 * @param v - vector to multiply
 * @param scalar - scalar to multiply to the vector
 * @return void
 * @post result = v * scalar
 */
void multiplyByScalar(Vector3 result, Vector3 v, GLfloat scalar);

/**
 * @brief adds 2 vectors together
 * 
 * @param result - vector to store the result of the calculation
 * @param v1 - first vector to add
 * @param v2 - second vector to add
 * @return void
 * @post result = v1 + v2
 */ 
void addVectors(Vector3 result, Vector3 v1, Vector3 v2);

/**
 * @brief subtracts 2 vectors from each other
 *
 * @param result - vector to store the result of the calculation
 * @param v1 - vector to subtract from
 * @param v2 - vector to subtract
 * @return void
 * @post result = v1 - v2
 */ 
void subtractVectors(Vector3 result, Vector3 v1, Vector3 v2);

/**
 * @brief multiplies two vectors together
 *
 * @param result - vector to store the result of the calculation
 * @param v1 - first vector to multiply
 * @param v1 - second vector to multiply
 * @return void
 * @post result = v1 * v2
 */
void multiplyVectors(Vector3 result, Vector3 v1, Vector3 v2);

/**
 * @brief calculates the dot product of two vectors
 *
 * @param v1 - first vector
 * @param v2 - second vector
 * @return GLfloat
 * @post dot product of v1 & v2 returned
 */ 
GLfloat calcDotProduct(Vector3 v1, Vector3 v2);

/**
 * @brief calculates the cross product of two vectors
 *
 * @param result - vector to store the result of the calculation
 * @param v1 - first vector
 * @param v2 - second vector
 * @return void
 * @post cross product of v1 & v2 returned
 */
void calcCrossProduct(Vector3 result, Vector3 v1, Vector3 v2);

/**
 * @brief calculate the magnitude (or length) of a vector
 *
 * @param v - the vector
 * @return float
 * @post magnitude (or length) of the paramter is returned
 */ 
float calcVecMagnitude(Vector3 v);

/**
 * @brief normalises a vector
 *
 * @param v - the vector to normalise
 * @return void
 * @post v becomes normalised
 */
void normaliseVector(Vector3 v);

/**
 * @brief calculates the normal vector of 3 points on a plane
 *
 * calculates vectors AB, AC
 * calculates the cross product of AB, AC
 * the normalised vector of this cross product is the normal vector of this plane
 *
 * @param result - vector to store the result of the calculation
 * @param A - point A on the plane
 * @param B - point B on the plane
 * @param C - point C on the plane
 * @return void
 * @post unit normal vector is calculated
 */ 
void calcUnitNormal(Vector3 result, Vector3 A, Vector3 B, Vector3 C);

/**
 * @brief calulates the direction at which the camera is facing, this is used to send a ball in that direction
 *
 * @param endDirection - the direction the camera is facing
 * @param cam - the camera
 * @param cueBall - the cue ball
 * @return void
 * @post vector from the camera to the cue ball is returned
 */
void calculateVelocityDirection(Vector3* endDirection, Camera* cam, Ball* cueBall);

#endif
