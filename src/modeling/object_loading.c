/*
 * FILE: object_loading.c
 * PURPOSE: function implementations for reading an OFF object file
 * DATE: 12/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (12/05/2024): initial file state
 *   Contributed by Kaden R, 34606207
 *
 */

#include "object_loading.h"

#include "../../lib/opengl/opengl.h"
#include "stdio.h"

Object3D* readOFFFile(const char* file_name, bool hasColour){
    FILE* fp;
    char line[1000];
    int lineNum = 0;
    int nvert, nfaces = 0;

    // Open file
    fp = fopen(file_name, "r");
    if (fp == NULL){
        printf("Error: file could not be opened.\n Press any key to exit ...");
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

    o->hasColour = hasColour;

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

            // read colour
            if (hasColour) {
                // set currently read characters to whitespace
                for (int j = 0; j < linePosition; j++) {
                    line[j] = ' ';
                }

                int redInt, greenInt, blueInt;
                GLfloat red, green, blue;

                sscanf(line, " %i %i %i", &redInt, &greenInt, &blueInt);

                red = (GLfloat)redInt / 255.f;
                green = (GLfloat)greenInt / 255.f;
                blue = (GLfloat)blueInt / 255.f;

                o->faces[currentFaceIndex].colour.red = red;
                o->faces[currentFaceIndex].colour.green = green;
                o->faces[currentFaceIndex].colour.blue = blue;
            }
            else {
                o->faces[currentFaceIndex].colour.red = 1;
                o->faces[currentFaceIndex].colour.green = 1;
                o->faces[currentFaceIndex].colour.blue = 1;
            }
        }
        lineNum++; // increment line number
    }
    fclose(fp);

    return o;
}
