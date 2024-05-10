#ifndef camera_h
#define camera_h

#include "../math/geometry.h"

enum CameraType {
    ORTHO2D, PERSPECTIVE, FRUSTUM, ORTHO
};

typedef struct Camera {
    enum CameraType cameraMode;
    Point3 position;
    Point3 lookat;
    Vector3 up;
} Camera;

#endif
