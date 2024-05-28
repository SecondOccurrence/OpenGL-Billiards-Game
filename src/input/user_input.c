/*
 * FILE: user_input.c
 * PURPOSE: function implementations to retrieve user input
 * DATE: 28/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (28/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */

#include "user_input.h"

#include <stdio.h>

#include "../globals/flags.h"
#include "../globals/general.h"

void userInput() {
    char shape;

    printf("Triangle/Rectangle (T/R): ");
    scanf("%s", &shape);
    if(shape == 'T' || shape == 't') {
        object_balls_shape = TRIANGLE;
    }
    else {
        object_balls_shape = RECTANGLE;
    }

    printf("Enter the number of spheres to display: ");
    scanf("%d", &object_balls_amount);
}
