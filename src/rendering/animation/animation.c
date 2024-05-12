/*
 * FILE: animation.h
 * PURPOSE: animation function definitions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (06/05/2024): added function to impose gravity on object
 *   Contributed by Josh S, 34195182
 * - v1.2 (07/05/2024): ballMovement now updates the balls position given all axis velocity
 *   Contributed by Josh S, 34195182
 * - v1.3 (08/05/2024): added ability to start/stop animation
 *   Contributed by Josh S, 34195182
 *
 */

#include "animation.h"

#include "../../data_structures/flags.h"
#include "../../math/collision.h"
#include "../../math/vector_operations.h"

#include "../../globals/flags.h"
#include "../../globals/objects.h"

#include <math.h>

extern const int TIMERMSECS;

#include <stdio.h>

void animate() {
    if(animation_flag == ANIMATION_ENABLED) {
        ballMovement(0.02);
    }

    glutPostRedisplay();
    glutTimerFunc(TIMERMSECS, animate, 0);
}

void ballMovement(float seconds) {
    const Vector3 gravity = {0.0f, -9.81f, 0.0f};

    GLfloat distance = distanceToPlane(ballProperties.position, planeProperties.points[0], planeProperties.points[1], planeProperties.points[2]);
    if(distance < ballProperties.radius) {
        Vector3 planeNormal;
        calcUnitNormal(planeNormal, planeProperties.points[0], planeProperties.points[1], planeProperties.points[2]);

        GLfloat perpendicular = calcDotProduct(ballProperties.velocity, planeNormal);

        for(int i = 0; i < 3; i++) {
            ballProperties.velocity[i] = (ballProperties.velocity[i] - 2 * perpendicular * planeNormal[i]) * planeProperties.bounciness;
        }

        ballProperties = resolveCollision(&ballProperties, distance, planeNormal);
    }

    ballProperties.velocity[1] += gravity[1] * seconds;

    const GLfloat threshold = 0.05f;
    for(int i = 0; i < 3; i++) {
        if(fabsf(ballProperties.velocity[i]) < threshold) {
            ballProperties.velocity[i] = 0.0f;
        }

        ballProperties.position[i] += ballProperties.velocity[i] * seconds;
    }
}
