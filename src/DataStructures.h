/*
 * FILE: DataStructures.h
 * PURPOSE: uncategorised data structures used throughout the program
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 *
 */

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

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

#endif
