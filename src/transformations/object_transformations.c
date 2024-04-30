/*
 * FILE: object_transformations.c
 * PURPOSE: function implementations that are responsible for any form of transformations
 *      on a 3d object in the scene
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#include "../../lib/opengl/opengl.h"

#include "object_transformations.h"

#include "../math/matrix_operations.h"

#include <math.h>

void translateObject(Object3D* obj, Vector3 translation) {
    Matrix4 projection = {{1, 0, 0, translation[0]},
                          {0, 1, 0, translation[1]},
                          {0, 0, 1, translation[2]},
                          {0, 0, 0, 1}};
    multiplyVerticesByMatrix(obj->vertices, obj->nvert, projection);
}

void rotateObject(Object3D* obj, GLfloat rotation, char axis) {
    const GLfloat PI = 3.14159;
    Matrix4 projection;
    GLfloat radians = rotation * PI / 180.0;
    if(axis == 'x') {
        projection[0][0] = 1.0;
        projection[0][1] = 0.0;
        projection[0][2] = 0.0;
        projection[0][3] = 0.0;

        projection[1][0] = 0.0;
        projection[1][1] = cos(radians);
        projection[1][2] = -sin(radians);
        projection[1][3] = 0.0;

        projection[2][0] = 0.0;
        projection[2][1] = sin(radians);
        projection[2][2] = cos(radians);
        projection[2][3] = 0.0;

        projection[3][0] = 0.0;
        projection[3][1] = 0.0;
        projection[3][2] = 0.0;
        projection[3][3] = 1.0;
    }
    else if(axis == 'y') {
        projection[0][0] = cos(radians);
        projection[0][1] = 0.0;
        projection[0][2] = sin(radians);
        projection[0][3] = 0.0;

        projection[1][0] = 0.0;
        projection[1][1] = 1.0;
        projection[1][2] = 0.0;
        projection[1][3] = 0.0;

        projection[2][0] = -sin(radians);
        projection[2][1] = 0.0;
        projection[2][2] = cos(radians);
        projection[2][3] = 0.0;

        projection[3][0] = 0.0;
        projection[3][1] = 0.0;
        projection[3][2] = 0.0;
        projection[3][3] = 1.0;
    }
    else if(axis == 'z') {
        projection[0][0] = cos(radians);
        projection[0][1] = -sin(radians);
        projection[0][2] = 0.0;
        projection[0][3] = 0.0;

        projection[1][0] = sin(radians);
        projection[1][1] = cos(radians);
        projection[1][2] = 0.0;
        projection[1][3] = 0.0;

        projection[2][0] = 0.0;
        projection[2][1] = 0.0;
        projection[2][2] = 1.0;
        projection[2][3] = 0.0;

        projection[3][0] = 0.0;
        projection[3][1] = 0.0;
        projection[3][2] = 0.0;
        projection[3][3] = 1.0; 
    }
    multiplyVerticesByMatrix(obj->vertices, obj->nvert, projection);
}

void scaleObject(Object3D* obj, Vector3 scaling) {
    Matrix4 projection = {{scaling[0], 0, 0, 0},
                          {0, scaling[1], 0, 0},
                          {0, 0, scaling[2], 0},
                          {0, 0, 0, 1}};
    multiplyVerticesByMatrix(obj->vertices, obj->nvert, projection);
}
