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

#include "initialisation.h"
#include "gl_callback.h"

#include "data_structures/geometry.h"
#include "movement/keyboard_utils.h"
#include "rendering/animation/animation.h"
#include "modeling/object_loading.h"

#include <stdbool.h>

const int TIMERMSECS = 20;
Shape table;

int main(int argc, char** argv) {
    // Load objects
    table.collision = readOFFFile("Table Collision_Simplified.off");
    table.drawing   = readOFFFile("table_coloured.off");

    // OpenGL/Glut stuff
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

    glutTimerFunc(TIMERMSECS, animate, 0);
    glutMainLoop();

    return 0;
}
