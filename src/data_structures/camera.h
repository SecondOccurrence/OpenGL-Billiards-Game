#ifndef camera_h
#define camera_h

#include "../math/geometry.h"

typedef struct Camera {
    Point3 position;
    Point3 lookat;
    Vector3 up;
} Camera;

enum CameraType {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
};

extern Camera camera;
extern enum CameraType cameraMode;

#endif
