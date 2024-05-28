#ifndef flags_h
#define flags_h

typedef enum {
    ANIMATION_DISABLED = 0, ANIMATION_ENABLED = 1
} AnimationFlag;

typedef enum {
    GRID_DISABLED = 0, GRID_ENABLED = 1
} GridFlag;

typedef enum {
    AXIS_DISABLED = 0, AXIS_ENABLED = 1
} AxisFlag;

typedef enum {
    OBJECTS_DISABLED = 0, OBJECTS_ENABLED = 1
} ObjectsFlag;

typedef enum {
    TRIANGLE = 0, RECTANGLE = 1
} ObjectBallsShape;

#endif
