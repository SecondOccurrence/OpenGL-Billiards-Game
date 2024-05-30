/*
 * FILE: main.c
 * PURPOSE: Main program
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (29/05/2024): added glutCloseFunc to run when closing the game
 *   Contributed by Kaden R, 34606207
 *
 */


#include "../lib/opengl/opengl.h"

#include "initialisation.h"
#include "gl_callback.h"

#include "data_structures/geometry.h"
#include "input/keyboard_utils.h"
#include "rendering/animation/animation.h"
#include "modeling/object_loading.h"
#include "input/user_input.h"

#include "globals/general.h"
#include "globals/objects.h"

const int TIMERMSECS = 20;

const int windowWidth = 1024;
const int windowHeight = 786;

int previousFrameTime = 0;
int currentFrameTime = 0;

extern ObjectBallsShape object_balls_shape;

int main(int argc, char** argv) {
    userInput();

    initialiseBalls(object_balls_amount);

    if(object_balls_shape == TRIANGLE) {
        initialiseTriangle();
    }
    else {
        initialiseRectangle();
    }

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB  | GLUT_DEPTH);

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ICT289");

    glutDisplayFunc(myDisplay);

    glutReshapeFunc(myReshape);

    glutKeyboardFunc(keys);

    init();

    glutCloseFunc(exitApplication);

    glutMainLoop();

    return 0;
}
