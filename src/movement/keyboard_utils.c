/*
 * FILE: keyboard_utils.c
 * PURPOSE: function implementation for keyboard utility functions
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): introduced mainKeys, for inputs that manipulate the core scene. also clean up of unused parameters
 *   Contributed by Josh S, 34195182
 *
 */


#include "keyboard_utils.h"

#include "../data_structures/camera.h"
#include "../math/geometry.h"
#include "../math/vector_operations.h"
#include "../transformations/object_transformations.h"

int hideGrid = 0;
int hideAxis = 0;
int hideObjects = 0;

void mainKeys(unsigned char key) {
    switch(key) {
    case 'Q':
    case 'q':
        exit(0);
        break;
    case 'G':
    case 'g':
        hideGrid ^= 1;
        break;
    case 'O':
    case 'o':
        hideAxis ^= 1;
        break;
    case 'L':
    case 'l':
        hideObjects ^= 1;
        break;
    }   
}

void cameraKeys(unsigned char key) {
    switch(key) {
    case 'X':
        strafeLeft();
        break;
    case 'x':
        strafeRight();
        break;
    case 'Y':
        camera.position[1] -= 0.1;
        camera.lookat[1] -= 0.1;
        break;
    case 'y':
        camera.position[1] += 0.1;
        camera.lookat[1] += 0.1;
        break;
    case 'Z':
        moveForward();
        break;
    case 'z':
        moveBackward();
        break;
    case 'F':
        viewFront();
        break;
    case 'R':
        viewRear();
        break;
    case 'T':
        viewTop();
        break;
    case 'B':
        viewBottom();
        break;
    case 'I':
        viewLeft();
        break;
    case 'L':
        viewRight();
        break;
    }
}

void strafeLeft() {
    Vector3 direction, result;

    subtractVectors(direction, camera.lookat, camera.position);
    calcCrossProduct(result, direction, camera.up);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera.position, camera.position, result);
    subtractVectors(camera.lookat, camera.lookat, result);
}

void strafeRight() {
    Vector3 direction, result;

    subtractVectors(direction, camera.lookat, camera.position);
    calcCrossProduct(result, direction, camera.up);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera.position, camera.position, result);
    addVectors(camera.lookat, camera.lookat, result);
}

void moveForward() {
    Vector3 result;

    subtractVectors(result, camera.lookat, camera.position);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera.position, camera.position, result);
    subtractVectors(camera.lookat, camera.lookat, result);
}

void moveBackward() {
    Vector3 result;

    subtractVectors(result, camera.lookat, camera.position);

    calcNormal(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera.position, camera.position, result);
    addVectors(camera.lookat, camera.lookat, result);
}

void viewFront() {
    camera.position[0] = 0.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 3.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewRear() {
    camera.position[0] = 0.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = -3.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewTop() {
    camera.position[0] = 0.0f;
    camera.position[1] = 3.0f;
    camera.position[2] = 0.0f;

    if(camera.up[1] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 0.0f;
        camera.up[2] = 1.0f;
    }
}

void viewBottom() {
    camera.position[0] = 0.0f;
    camera.position[1] = -3.0f;
    camera.position[2] = 0.0f;

    if(camera.up[1] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 0.0f;
        camera.up[2] = 1.0f;
    }
}

void viewRight() {
    camera.position[0] = 3.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 0.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void viewLeft() {
    camera.position[0] = -3.0f;
    camera.position[1] = 0.0f;
    camera.position[2] = 0.0f;

    if(camera.up[2] != 0.0f) {
        camera.up[0] = 0.0f;
        camera.up[1] = 1.0f;
        camera.up[2] = 0.0f;
    }
}

void transformKeys(unsigned char key, Object3D* obj) {
    Vector3 transformation = {0.0, 0.0, 0.0};
    switch(key) {
    case 'a':
        transformation[0] = -0.25;
        transformation[1] = 0.0;
        transformation[2] = 0.0;
        translateObject(obj, transformation); 
        break;
    case 'd':
        transformation[0] = 0.25;
        transformation[1] = 0.0;
        transformation[2] = 0.0;
        translateObject(obj, transformation);
        break;
    case 'w':
        transformation[0] = 0.0;
        transformation[1] = 0.25;
        transformation[2] = 0.0;
        translateObject(obj, transformation);
        break;
    case 's':
        transformation[0] = 0.0;
        transformation[1] = -0.25;
        transformation[2] = 0.0;
        translateObject(obj, transformation);
        break;
    case 'U':
        transformation[0] = 0.0;
        transformation[1] = 0.0;
        transformation[2] = 0.25;
        translateObject(obj, transformation);
        break;
    case 'u':
        transformation[0] = 0.0;
        transformation[1] = 0.0;
        transformation[2] = -0.25;
        translateObject(obj, transformation);
        break;
    case '0':
        rotateObject(obj, 10, 'z');
        break;
    case '1':
        rotateObject(obj, -10, 'z');
        break;
    case '+':
        transformation[0] = 1.25;
        transformation[1] = 1.25;
        transformation[2] = 1.25;
        scaleObject(obj, transformation);
        break;
    case '-':
        transformation[0] = 0.75;
        transformation[1] = 0.75;
        transformation[2] = 0.75;
        scaleObject(obj, transformation);
        break;
    }
}

void specialKeys(int key, int x, int y) {
    //rotationKeys(key, x, y, &bone);

    glutPostRedisplay();
}

void rotationKeys(int key, Object3D* obj) {
    switch(key) {
    case GLUT_KEY_LEFT:
        rotateObject(obj, -10, 'x');
        break;
    case GLUT_KEY_RIGHT:
        rotateObject(obj, 10, 'x');
        break;
    case GLUT_KEY_UP:
        rotateObject(obj, 10, 'y');
        break;
    case GLUT_KEY_DOWN:
        rotateObject(obj, -10, 'y');
        break;
    } 
}
