/*
 * FILE: animation.h
 * PURPOSE: animation function definitions
 * DATE: 05/05/2024
 *
 * VERSION HISTORY:
 * - v1.0 (05/05/2024): initial file state
 *   Contributed by Josh S, 34195182
 * - v1.1 (06/05/2024): added function to impose gravity on object
 *   Contributed by Josh S, 34195182
 * - v1.2 (08/05/2024): added physics for ball moving down sloped plane
 *
 */


#ifndef animation_h
#define animation_h

#include "../../../lib/opengl/opengl.h"

#include "../../data_structures/camera.h"
#include "../../data_structures/flags.h"
#include "../../data_structures/objects.h"

/**
 * @brief adjusts the hold time for a cue shot and updates cue balls velocity accordingly
 *
 * @param cueHitFlag - flag storing cue sticks state
 * @param spacebarHoldTime - power value indicating how long the cue stick has been charging a shot
 * @param maxPower - the maximum amount of power spacebarHoldTime can hold
 * @param cueBall - the cue ball
 * @param camera - the camera
 * @return void
 * @post cue stick will continue charging if state indicated so, if the state indicated cue has been released,
 *      a vector is calculated holding the orentation of the camera, this is imposed on the cueBall's velocity
 */
void prepareForHit(CueHitFlag* cueHitFlag, float* spacebarHoldTime, const float* maxPower, Ball* cueBall, Camera* camera);

/**
 * @brief checks if any ball has collided with a pocket
 *
 * @param table - the table struct containing the pocket coordinates
 * @param cueBall - the cue ball
 * @param objectBalls - the object balls
 * @param objectBallsSize - the amount of objectBalls
 * @param camera - the camera
 * @return void
 * @post if a ball has collided with any pocket, it will be taken off the table
 */
void checkPockets(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize, Camera* camera);

/**
 * @brief checks for any form of collision for all balls
 *
 * @param table - the table
 * @param cueBall - the cue ball
 * @param objectBalls - the object balls
 * @param objectBallsSize - the amount of object balls
 * @return void
 * @post checks for collisions and resolves them for each ball
 */
void checkForCollisions(Shape* table, Ball* cueBall, Ball* objectBalls, int objectBallsSize);

/**
 * @brief updates all balls properties on a new frame. adjusts the balls position with respect to its current velocity
 *
 * @param cueBall - the cue ball
 * @param objectBalls - the object balls
 * @param objectBallsSize - the amount of object balls
 * @param seconds - time passed since the last frame
 * @return void
 * @post updates all balls position
 */
void ballMovement(Ball* cueBall, Ball* objectBalls, int objectBallsSize, float seconds);

/**
 * @brief updates a ball's position with respect to its velocity
 *
 * @param ball - the ball to adjust
 * @param gravity - gravity constant to impose on the ball
 * @param seconds - time passed sicne last frame
 * @return void
 * @post balls position is updated
 */ 
void updateVelocity(Ball* ball, GLfloat gravity, float seconds);

/**
 * @brief container function containing logic for if the camera should turn clockwise or anticlockwise
 *
 * @param rotationFlag - flag indicated if the camera should be rotating
 * @param camera - the camera
 * @param cueBall - the cue ball
 * @param changeInSeconds - time since last frame
 * @return void
 * @post camera begins rotating if user presses the right button
 */
void rotateCameraContinuous(RotationFlag* rotationFlag, Camera* camera, Ball* cueBall, float changeInSeconds);

/**
 * @brief rotates the camera clockwise around the cue ball
 *
 * @param camera - the camera
 * @param cueBall - the cue ball
 * @param angle - the angle to rotate around the cue ball
 * @return void
 * @post camera rotates in an increment around the camera clockwise
 */
void rotateCameraClockwise(Camera* camera, Ball* cueBall, float angle);

/**
 * @brief rotates the camera anticlockwise around the cue ball
 *
 * @param camera - the camera
 * @param cueBall - the cue ball
 * @param angle - the angle to rotate around the cue ball
 * @return void
 * @post camera rotates in an increment around the camera anticlockwise
 */
void rotateCameraCounterclockwise(Camera* camera, Ball* cueBall, float angle);

/**
 * @brief determines the camera position dependent on if the cue ball is moving
 *
 * @param previousMoveCheck - checks if the ball was moving last frame
 * @param camera - the camera
 * @param cueBall - the cue ball
 * @param deltaTime - change in time since last frame
 * @return void
 * @post if the cue ball isn't moving, camera is in first person view looking at the cue ball
 *      if the cue ball is moving, the camera is looking down on the pool table
 */
void updateCameraPosition(int* previousMoveCheck, Camera* camera, Ball* cueBall, float deltaTime);

/**
 * @brief sets the camera's properties back to its default values
 * 
 * @param camera - the camera
 * @param newLookat - the point to look at
 * @return void
 * @post - adjusts camera properties to look back at the cue ball
 */
void resetCamera(Camera* camera, Point3* newLookat);

#endif
