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
 * - v1.1 (10/05/2024): removed globals
 *   Contributed by Josh S, 34195182
 * - v1.2 (12/05/2024): added keys to alter ball velocity
 *   Contributed by Josh S, 34195182
 *
 */

#include "keyboard_utils.h"

#include "../math/vector_operations.h"

void toggleKeys(unsigned char key, AnimationFlag* animation_flag, GridFlag* grid_flag, AxisFlag* axis_flag, ObjectsFlag* objects_flag) {
    switch(key) {
    case 'P':
    case 'p':
        if(*animation_flag == ANIMATION_ENABLED) {
            *animation_flag = ANIMATION_DISABLED;
        }
        else {
            *animation_flag = ANIMATION_ENABLED;
        }
        break;
    case 'G':
    case 'g':
        if(*grid_flag == GRID_ENABLED) {
            *grid_flag = GRID_DISABLED;
        }
        else {
            *grid_flag = GRID_ENABLED;
        }
        break;
    case 'O':
    case 'o':
        if(*axis_flag == AXIS_ENABLED) {
            *axis_flag = AXIS_DISABLED;
        }
        else {
            *axis_flag = AXIS_ENABLED;
        }
        break;
    case 'L':
    case 'l':
        if(*objects_flag == OBJECTS_ENABLED) {
            *objects_flag = OBJECTS_DISABLED;
        }
        else {
            *objects_flag = OBJECTS_ENABLED;
        }
        break;
    case 27:
        glutLeaveMainLoop();
        break;
    default:
        break;
    }
}

BallProperties objectKeys(unsigned char key, BallProperties* objectProperties) {
    switch(key) {
    case 'd':
        objectProperties->velocity[0] += 0.5f;
        break;
    case 'a':
        objectProperties->velocity[0] -= 0.5f;
        break;
    case 'w':
        objectProperties->velocity[1] += 1.0f;
        break;
    case 's':
        objectProperties->velocity[1] -= 1.0f;
        break;
    case 'q':
        objectProperties->velocity[2] += 0.5f;
        break;
    case 'e':
        objectProperties->velocity[2] -= 0.5f;
        break;
    default:
        break;
    }

    return *objectProperties;
}

void cameraKeys(unsigned char key, Camera* camera, RotationFlag* rotation_flag_c, RotationFlag* rotation_flag_a) {
    switch(key) {
    case 'X':
        strafeLeft(camera);
        break;
    case 'x':
        strafeRight(camera);
        break;
    case 'Y':
        camera->position[1] -= 0.1;
        camera->lookat[1] -= 0.1;
        break;
    case 'y':
        camera->position[1] += 0.1;
        camera->lookat[1] += 0.1;
        break;
    case 'Z':
        moveForward(camera);
        break;
    case 'z':
        moveBackward(camera);
        break;
    case 'F':
        viewFront(camera);
        break;
    case 'R':
        viewRear(camera);
        break;
    case 'T':
        viewTop(camera);
        break;
    case 'B':
        viewBottom(camera);
        break;
    case 'I':
        viewLeft(camera);
        break;
    case 'L':
        viewRight(camera);
        break;
    case 'N':
    case 'n':
        *rotation_flag_c = ROTATION_DISABLED;
        if(*rotation_flag_a == ROTATION_DISABLED) {
            *rotation_flag_a = ROTATION_ENABLED;
        }
        else {
            *rotation_flag_a = ROTATION_DISABLED;
        }
        break;
    case 'M':
    case 'm':
        *rotation_flag_a = ROTATION_DISABLED;
        if(*rotation_flag_c == ROTATION_DISABLED) {
            *rotation_flag_c = ROTATION_ENABLED;
        }
        else {
            *rotation_flag_c = ROTATION_DISABLED;
        }
        break;
    case 'V':
    case 'v':
        resetCamera(camera);
        break;
    default:
        break;
    }
}

void strafeLeft(Camera* camera) {
    Vector3 direction, result;

    subtractVectors(direction, camera->lookat, camera->position);
    calcCrossProduct(result, direction, camera->up);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera->position, camera->position, result);
    subtractVectors(camera->lookat, camera->lookat, result);
}

void strafeRight(Camera* camera) {
    Vector3 direction, result;

    subtractVectors(direction, camera->lookat, camera->position);
    calcCrossProduct(result, direction, camera->up);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera->position, camera->position, result);
    addVectors(camera->lookat, camera->lookat, result);
}

void moveForward(Camera* camera) {
    Vector3 result;

    subtractVectors(result, camera->lookat, camera->position);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    subtractVectors(camera->position, camera->position, result);
    subtractVectors(camera->lookat, camera->lookat, result);
}

void moveBackward(Camera* camera) {
    Vector3 result;

    subtractVectors(result, camera->lookat, camera->position);

    normaliseVector(result);
    multiplyByScalar(result, 0.5);

    addVectors(camera->position, camera->position, result);
    addVectors(camera->lookat, camera->lookat, result);
}

void resetCamera(Camera* camera) {
    for (int i = 0; i < 3; ++i) {
        camera->position[i] = camera->initialPosition[i];
        camera->lookat[i] = camera->initialLookat[i];
        camera->up[i] = camera->initialUp[i];
    }
}

void viewFront(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 3.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewRear(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = -3.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewTop(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = 3.0f;
    camera->position[2] = 0.0f;

    if(camera->up[1] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 0.0f;
        camera->up[2] = 1.0f;
    }
}

void viewBottom(Camera* camera) {
    camera->position[0] = 0.0f;
    camera->position[1] = -3.0f;
    camera->position[2] = 0.0f;

    if(camera->up[1] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 0.0f;
        camera->up[2] = 1.0f;
    }
}

void viewRight(Camera* camera) {
    camera->position[0] = 3.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 0.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}

void viewLeft(Camera* camera) {
    camera->position[0] = -3.0f;
    camera->position[1] = 0.0f;
    camera->position[2] = 0.0f;

    if(camera->up[2] != 0.0f) {
        camera->up[0] = 0.0f;
        camera->up[1] = 1.0f;
        camera->up[2] = 0.0f;
    }
}
