cmake_minimum_required(VERSION 3.29)

if(WIN32)
    set(FREEGLUT_DLL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/opengl/freeglut.dll")
    # glu32 and openGL32 are part of the windows sdk by default
    target_link_libraries(output PRIVATE FREEGLUT_DLL_PATH glu32 openGL32)
elseif(UNIX)
    # assumes opengl and freeglut are installed on the system
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)

	target_link_libraries(output PRIVATE OpenGL::GL GLUT::GLUT GLU m)
endif()
