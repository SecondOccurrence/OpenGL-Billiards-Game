/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for object transformations
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
