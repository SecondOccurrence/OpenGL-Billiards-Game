#ifndef OPENGL_H
#define OPENGL_H

//---------------------------------------------------------------------------------

#ifdef _WIN32
    #include <GL/freeglut.h>
#elif __APPLE__
    #include <GL/glut.h>
#elif __unix__
    #include <GL/freeglut.h>
#endif

//---------------------------------------------------------------------------------

#endif

