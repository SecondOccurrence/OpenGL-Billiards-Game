/*
 * FILE: object_loading.h
 * PURPOSE: function definitions for reading an OFF object file
 * DATE: 12/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (12/05/2024): initial file state
 *   Contributed by Kaden R, 34606207
 * - v1.1 (16/05/2024): changed colour input processing to suit changes with Colour type
 *   Contributed by Kaden R, 34606207
 * - v1.2 (18/05/2024): updated "file not found" error to include filename.
 *                      readOFFFile now returns Object3D (changed from Object3D*).
 *   Contributed by Kaden R, 34606207
 * - v1.3 (18/05/2024): readOFFFile now automatically detects colour
 *   Contributed by Kaden R, 34606207
 * - v1.4 (20/05/2024): Reverted change from Object3D* to Object3D (is now Object3D*)
 *   Contributed by Kaden R, 34606207
 * - v1.5 (29/05/2024): added function to free a Shape's memory
 *                      added header guard
 *   Contributed by Kaden R, 34606207
 *
 */

#ifndef OBJECT_LOADING_H
#define OBJECT_LOADING_H

#include "../data_structures/geometry.h"

/**
 * @brief reads object data from an OFF file
 *
 * @param file_name - path to the file to read
 * @return Object3D* address to the data struct storing the off file data
 * @post read the OFF file and stores the data in a struct, this struct's address is returned.
 */
Object3D* readOFFFile(const char* file_name);

/**
 * @brief frees memory before exiting program
 *
 * @return void
 * @pre table struct and object balls have allocated memory
 * @post table struct and object balls' memory are free'd
 */
void exitApplication(void);

#endif

