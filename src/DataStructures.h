typedef struct Point {
    float x, y, z;
} Point;

typedef struct FacePoint {
    int face1, face2, face3;
} FacePoint;

typedef Point Vector;

typedef struct OFF_FILE {
    int nvert, nfaces, nedges;
    Point* verticiesData;
    FacePoint* faceData;
} OFF_FILE;
