#ifndef camera_h
#define camera_h

#include "geometry.h"

typedef enum {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
} CameraType;

typedef struct Camera {
    CameraType cameraMode;
    Point3 position;
    Point3 lookat;
    Vector3 up;
    Vector3 initialPosition;
    Vector3 initialLookat;
    Vector3 initialUp;
} Camera;

#endif
