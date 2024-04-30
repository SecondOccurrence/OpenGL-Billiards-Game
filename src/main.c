/*
 * FILE: main.c
 * PURPOSE: Main program
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */


#include "../lib/opengl/opengl.h"

#include "main_functions.h"

#include "math/geometry.h"
#include "modeling/drawing_utilities.h"
#include "movement/keyboard_utils.h"

Object3D bone;

int main(int argc, char** argv) {
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB  | GLUT_DEPTH);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Exercise 2.1");

    glutDisplayFunc(myDisplay);

    glutReshapeFunc(myReshape);

    glutKeyboardFunc(keys);
    //glutSpecialFunc(specialKeys);

    init();

    glutMainLoop();

    return 0;
}
