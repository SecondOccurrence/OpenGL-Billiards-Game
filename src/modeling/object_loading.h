/*
 * FILE: object_loading.h
 * PURPOSE: function definitions for reading an OFF object file
 * DATE: 12/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (12/05/2024): initial file state
 *   Contributed by Kaden R, 34606207
 *
 */

#include "../data_structures/geometry.h"

Object3D* readOFFFile(const char* file_name, bool hasColour);
