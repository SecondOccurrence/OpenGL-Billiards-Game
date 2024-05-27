/*
 * AUTHOR: Josh S
 * STUDENT NUMBER: 34195182
 * DATE: 24/04/2024
 *
 * DESCRIPTION: Function declarations for the main program
 *
 */

#ifndef main_functions_h
#define main_functions_h

void init();

void setLight(void);

void setCamera(int cameraMode);

/**
 * @brief Gets user input for the shape type and the number of spheres
 */
void userInput();

/**
 * @brief Displays spheres in a rectangular grid layout with maximum 5 spheres in each row
 */
void displayRectangle();

/**
 * @brief Displays spheres in a triangular layout
 */
void displayTriangle();

void myDisplay();

void myReshape(int width, int height);

#endif // main_functions_h
