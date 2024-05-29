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
#include "input/keyboard_utils.h"
#include "rendering/animation/animation.h"
#include "input/user_input.h"

const int TIMERMSECS = 20;

const int windowWidth = 1024;
const int windowHeight = 786;

int previousFrameTime = 0;
int currentFrameTime = 0;

int main(int argc, char** argv) {
    //userInput();

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB  | GLUT_DEPTH);

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ICT289");

    glutDisplayFunc(myDisplay);

    glutReshapeFunc(myReshape);

    glutKeyboardFunc(keys);

    init();

    glutMainLoop();

    return 0;
}
