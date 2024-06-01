#include "text.h"

#include "../../lib/opengl/opengl.h"

#include "../globals/general.h"
#include "../globals/objects.h"

#include <stdio.h>

void text_power() {
    // set colour
    glColor3f(1.0f, 0.335f, 0.1f);
    // set position
    int x_pos = 100;
    int y_pos = 80;

    // set string
    char str[20];
    int powerPercentage = (int)(spacebarHoldTime/maxPower*100);
    if (powerPercentage > 98.5) powerPercentage = 100; // powerPercentage stops at 99, check if it is above 98.5 and set to 100 if so
    sprintf(str, "Power: %i%%", powerPercentage);

    // display string
    glRasterPos2f(x_pos, y_pos);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)str);
}

void text_remaining() {
    // set colour
    glColor3f(1.0f, 0.335f, 0.1f);
    // set position
    int x_pos = 100;
    int y_pos = 120;

    // count all not pocketed balls
    int count = 0;
    for (int i = 0; i < object_balls_amount; i++) {
        if (balls[i].pocketed == 0) count++;
    }

    // set string
    char str[20];
    sprintf(str, "Balls Remaining: %i", count);

    // display string
    glRasterPos2f(x_pos, y_pos);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)str);
}
