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
 * - v1.2 (26-29/05/2024): many additions. checking for pockets ball-wall collision ball-ball collision
 *   Contributed by Josh S, 34195182
 * - v1.2 (31/05/2024): refactored code
 *   Contributed by Josh S, 34195182
 * - v1.3 (01/06/2024): refined ball-ball collision to simulate more accurate physics
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

void ballPlaneCollision(Ball* cueBall, PlaneProperties* collider, int planeIndex) {
    GLfloat velocity;
    GLfloat velocityThreshold = 0.1f;

    GLfloat distance = distanceToPlane(cueBall->ball.position, collider->points[0], collider->points[1], collider->points[2]);

    if(distance < (cueBall->ball.radius)) {
        Vector3 planeNormal;
        calcUnitNormal(planeNormal, collider->points[0], collider->points[1], collider->points[2]);

        GLfloat perpendicular = calcDotProduct(cueBall->velocity, planeNormal);

        for(int j = 0; j < 3; j++) {
            velocity = cueBall->velocity[j] - 2 * perpendicular * planeNormal[j];
            velocity *= collider->bounciness;
            cueBall->velocity[j] = velocity;
        }

        *cueBall = resolveCollision(cueBall, distance, planeNormal, planeIndex);
    }
}

Ball resolveCollision(Ball* ball, GLfloat distance, Vector3 planeNormal, int wallIteration) {
    if(wallIteration == 0 || wallIteration == 1 || wallIteration == 2) {
        multiplyByScalar(planeNormal, planeNormal, -1);
    }

    for(int i = 0; i < 3; i++) {
        ball->ball.position[i] += (ball->ball.radius - distance) * planeNormal[i];
    }
    return *ball;
}

int collidesWithPocket(Ball* ball, Sphere* pocket) {
    int foundCollision = 0;

    Vector3 collisionNormal;
    subtractVectors(collisionNormal, ball->ball.position, pocket->position);
    GLfloat distance = calcDotProduct(collisionNormal, collisionNormal);
    for(int i = 0; i < 3; i++) {
        collisionNormal[i] /= distance;
    }

    if(distance <= (ball->ball.radius + pocket->radius)) {
        foundCollision = 1;        
    }

    return foundCollision;
}

void ballToBallCollision(Ball* ball1, Ball* ball2) {
    Vector3 collisionNormal;
    subtractVectors(collisionNormal, ball1->ball.position, ball2->ball.position);
    normaliseVector(collisionNormal);

    GLfloat distance = calculateDistance(&ball1->ball.position, &ball2->ball.position);
    GLfloat penetrationDepth = (ball1->ball.radius + ball2->ball.radius) - distance;
    if(penetrationDepth > 0.0f) {
        resolvePenetration(ball1, ball2, penetrationDepth, &collisionNormal);

        Vector3 impulse;
        calculateImpulse(&impulse, ball1, ball2, &collisionNormal);

        GLfloat maxImpulseMagnitude = 14.0f;
        GLfloat impulseMagnitude = calcVecMagnitude(impulse);

        if(impulseMagnitude > maxImpulseMagnitude) {
            GLfloat scale = maxImpulseMagnitude / impulseMagnitude;
            multiplyByScalar(impulse, impulse, scale);
        }

        for(int i = 0; i < 3; i++) {
            ball1->velocity[i] += impulse[i] / ball1->mass;
            ball2->velocity[i] -= impulse[i] / ball2->mass;
        }
    }
}

GLfloat calculateDistance(Vector3* pos1, Vector3* pos2) {
    Vector3 d;
    subtractVectors(d, *pos2, *pos1);
    return sqrt((d[0] * d[0]) + (d[1] * d[1]) + (d[2] * d[2]));
}

void resolvePenetration(Ball* ball1, Ball* ball2, GLfloat penDepth, Vector3* normal) {
    Vector3 ball1Displacement;
    multiplyByScalar(ball1Displacement, *normal, penDepth * 0.5);
    addVectors(ball1->ball.position, ball1->ball.position, ball1Displacement);

    Vector3 ball2Displacement;
    multiplyByScalar(ball2Displacement, *normal, -penDepth * 0.5);
    addVectors(ball2->ball.position, ball2->ball.position, ball2Displacement);
}

void calculateImpulse(Vector3* impulseVector, Ball* ball1, Ball* ball2, Vector3* collisionNormal) {
    const GLfloat impulseScaleFactor = 0.75f;
    const GLfloat elasticity = 0.4f;
    Vector3 relativeVelocity;
    subtractVectors(relativeVelocity, ball2->velocity, ball1->velocity);

    GLfloat relativeVelocityAlongNormal = calcDotProduct(relativeVelocity, *collisionNormal);
    GLfloat impulseMagnitude = (1 + elasticity) * relativeVelocityAlongNormal * impulseScaleFactor;

    (*impulseVector)[0] = (*collisionNormal)[0];
    (*impulseVector)[1] = (*collisionNormal)[1];
    (*impulseVector)[2] = (*collisionNormal)[2];
    multiplyByScalar(*impulseVector, *impulseVector, impulseMagnitude);
}
