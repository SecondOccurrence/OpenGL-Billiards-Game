/*
 * FILE: initialisation.h
 * PURPOSE: function definitions for functions used in the main program file
 * DATE: 30/04/2024
 *
 * VERSION HISTORY:
 * - v1.0 (30/04/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (05/05/2024): extracting opengl callback functiong, leaving only intialisation functions
 *      renamed file from main_functions to intialisation
 *   Contributed by Josh S, 34195182
 *
 */


#ifndef initialisation_h
#define initialisation_h

/**
 * @brief Method which copies over class data with a deep copy
 *
 * This method is called recursively to delete children nodes
 *
 * @return bool
 * @post Deep copy of root is made
 *
 */

/**
 * @brief Initialises opengl parameters, the camera, and the light
 *
 * @return void
 * @post Lighting is placed on the screen, camera is set in the scene
 */
void init();

/**
 * @brief sets a simple light in the scene
 *
 * @return void
 * @post creates a simple light and places it in the scene
 */
void setLight(void);

/**
 * @brief assigns camera parameters depending on the camera type
 *
 * @param cameraMode - integer representing the type of camera used
 * @return void
 * @pre the camera's camera mode has been assigned
 * @post gl function is called to assign values to the respective camera type
 */
void setCamera(int cameraMode);

#endif
