/*
 * FILE: object_loading.c
 * PURPOSE: function implementations for reading an OFF object file
 * DATE: 12/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (12/05/2024): initial file state
 *   Contributed by Kaden R, 34606207
 * - v1.1 (16/05/2024): changed colour input processing to suit changes with Colour type
 *   Contributed by Kaden R, 34606207
 * - v1.2 (18/05/2024): updated "file not found" error to include filename
 *                      readOFFFile now returns Object3D (changed from Object3D*)
 *   Contributed by Kaden R, 34606207
 * - v1.3 (18/05/2024): readOFFFile now automatically detects colour
 *   Contributed by Kaden R, 34606207
 * - v1.4 (20/05/2024): Reverted change from Object3D* to Object3D (is now Object3D*)
 *   Contributed by Kaden R, 34606207
 *
 */

#include "object_loading.h"

#include "../../lib/opengl/opengl.h"
#include "stdio.h"

Object3D* readOFFFile(const char* file_name) {
    FILE* fp;
    char line[1000];
    int lineNum = 0;
    int nvert, nfaces = 0;

    // Open file
    fp = fopen(file_name, "r");
    if (fp == NULL){
        printf("Error: file \"%s\" could not be found.\n Press any key to exit ...", file_name);
        getchar();
        exit(0);
    }

    // Read contents
    rewind(fp); // read from beginning

    for (int i = 0; i < 2; i++) {
        fgets(line, 1000, fp);
        if (lineNum == 0) {
            if (!strcasecmp(line, "OFF")) { // if first line does not begin with "OFF" then exit
                printf("Error: file is not of type OFF.\n Press any key to exit ...");
                getchar();
                exit(0);
            }
        }
        else if (lineNum == 1) {
            sscanf(line, "%i %i", &nvert, &nfaces);
        }
        lineNum++; // increment line number
    }

    // allocate memory
    Object3D* o = (Object3D*)malloc(sizeof(Object3D));
    o->vertices = (Point3*)malloc(sizeof(Point3) * nvert);
    o->faces = (Face*)malloc(sizeof(Face) * nfaces);

    // begin setting variables
    o->nvert = nvert;
    o->nfaces = nfaces;

    bool hasColour = false;

    while (fgets(line, 1000, fp) != NULL) {
        if (lineNum < (o->nvert + 2)) { // all vertices
            int currentVertexIndex = lineNum - 2; // get the current index of array by getting the line number, subtracting the lines of vertices, and subtracting first 2 lines.
            sscanf(line, "%f %f %f", &o->vertices[currentVertexIndex][0], &o->vertices[currentVertexIndex][1], &o->vertices[currentVertexIndex][2]); // insert x, y and z values into the vertex array
        }

        else { // all faces (remaining lines)
            // get vertex count from first integer
            int linePosition = 0; // stores characters read from line (for sequential reading)
            int currentFaceIndex = lineNum - o->nvert - 2; // get the current index of array by getting the line number, subtracting the lines of vertices, and subtracting line 1.
            sscanf(line, "%i%n", &o->faces[currentFaceIndex].vertexCount, &linePosition); // read vertex count and characters read

            for (int i = 0; i < o->faces[currentFaceIndex].vertexCount; i++) { // for the number of vertices that the current face is made from
                // set currently read characters to whitespace
                for (int j = 0; j < linePosition; j++) {
                    line[j] = ' ';
                }
                // read next value
                sscanf(line, " %i%n", &o->faces[currentFaceIndex].vertices[i], &linePosition); // read next vertex and insert into the face's vertex array
            }

            // If first time iterating, check if colour exists
            if (currentFaceIndex == 0) {
                int redInt, greenInt, blueInt;
                int scanfReturnValue = sscanf(line, " %i %i %i", &redInt, &greenInt, &blueInt);
                if (scanfReturnValue == 3) hasColour = true; // if 3 values were read colour exists in file
                else hasColour = false;
            }

            // read colour if available, else set colour to white (1,1,1)
            if (hasColour) {
                // set currently read characters to whitespace
                for (int j = 0; j < linePosition; j++) {
                    line[j] = ' ';
                }

                Colour c = {0,0,0};
                int redInt, greenInt, blueInt;
                GLfloat red, green, blue;

                sscanf(line, " %i %i %i", &redInt, &greenInt, &blueInt);

                o->faces[currentFaceIndex].colour[0] = (GLfloat)redInt / 255.f;
                o->faces[currentFaceIndex].colour[1] = (GLfloat)greenInt / 255.f;
                o->faces[currentFaceIndex].colour[2] = (GLfloat)blueInt / 255.f;
            }
            else {
                for (int i = 0; i < 3; i++) o->faces[currentFaceIndex].colour[i] = 1;
            }
        }
        lineNum++; // increment line number
    }
    fclose(fp);

    // add colour detection result
    o->hasColour = hasColour;
    return o;
}
