This is a group project for a final assignment as part of a Computer Graphics Programming unit at University.

# Project Description:
This project simulates a game of pool / billiards. The aim is to sink all of the object balls in the pool table pockets. The user can decide whether or not to generate the object balls in a triangular or rectangular shape. 

The user can also decide how many object balls to generate. These object balls are generated with random masses, and their masses are shown by their colour.

# Authors
- [Josh Smith](https://github.com/SecondOccurrence): Physics
- [Abhijeet Sodhi](https://github.com/Abhijatt1): Camera work
- [Keegan Watson](https://github.com/KWKeegs): Ball work
- [Kaden Rossi](https://github.com/Seller9): 3D design and lighting

# User Guide

## Building the project
Requires CMake minimum version 3.29

- Create new directory ```./build```
- In the root directory, run ```cmake -S . -B build```
- In the root directory, run ```cmake --build build```
- Run the executable found in the ```./build``` directory, named ```output``` (```./build/output```)

## Playing the game
A console will appear asking to generate the object balls in a triangular shape or rectangular
- Choose 'T' (triangular) or 'R' (rectangular)

You will next be asked how many object balls to generate
- Choose a number (for a standard game, 15)

### Keybinds
- ```'A’/’a’```
  - Hold this key to rotate around the ball clockwise

- ```‘D’/’d’```
  - Hold this key to rotate around the ball anticlockwise

- ```SPACEBAR```
  - Press this key once to begin charging your shot. You will begin to see the power meter go up on the top left
  - Press this key again to release the shot, shooting the cue ball in the direction that you are facing

- ```‘P’/’p’```
  - Pressing this button pauses the game. To unpause, press it again

- ```‘G’/’g’```
  - Pressing this button shows a white wired grid on the screen. Pressing it again will hide this grid

- ```‘O’/’o’```
  - Pressing this button shows the x-y-z axis lines. Pressing it again will hide this

- ```‘L’/’l’```
  - Pressing this button will hide objects. Pressing it again will show them again


# Sample Gameplay
[https://youtu.be/RUy-5RXXbIw](https://youtu.be/RUy-5RXXbIw)

[![Video Preview](http://img.youtube.com/vi/RUy-5RXXbIw/0.jpg)](https://youtu.be/RUy-5RXXbIw)
