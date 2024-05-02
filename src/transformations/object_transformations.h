/*
 * FILE: object_transformations.h
 * PURPOSE: function definitions that are responsible for any sort of transformations on
 *      objects within the 3d scene
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef object_transformations_h
#define object_transformations_h

#include "../../lib/opengl/opengl.h"

#include "../math/geometry.h"

void translateObject(Object3D* obj, Vector3 translation);

void rotateObject(Object3D* obj, GLfloat rotation, char axis);

void scaleObject(Object3D* obj, Vector3 scaling);

#endif
