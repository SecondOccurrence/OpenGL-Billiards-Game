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
 *
 */

#include "../data_structures/geometry.h"

Object3D readOFFFile(const char* file_name);
