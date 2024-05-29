/*
 * FILE: collision.c
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

#include "collision.h"

#include "../data_structures/geometry.h"
#include "vector_operations.h"

#include <math.h>

GLfloat distanceToPlane(Point3 ballCenter, Point3 p1, Point3 p2, Point3 p3) {
    Vector3 normal = {0.0, 0.0, 0.0};
    calcUnitNormal(normal, p1, p2, p3);

    GLfloat D = (normal[0] * p1[0]) + (normal[1] * p1[1]) + (normal[2] * p1[2]);

    GLfloat distance = fabsf((normal[0] * ballCenter[0]) + (normal[1] * ballCenter[1]) + (normal[2] * ballCenter[2]) - D);
    distance /= sqrtf((normal[0] * normal[0]) + (normal[1] * normal[1]) + (normal[2] * normal[2]));

    return distance;
}

BallProperties resolveCollision(BallProperties* ball, GLfloat distance, Vector3 planeNormal, int wallIteration) {
    if(wallIteration == 0 || wallIteration == 1 || wallIteration == 2) {
        multiplyByScalar(planeNormal, -1);
    }

    for(int i = 0; i < 3; i++) {
        ball->ball.position[i] += (ball->ball.radius - distance) * planeNormal[i];
    }
    return *ball;
}
