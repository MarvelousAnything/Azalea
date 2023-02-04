#ifndef AZALEA_GLADUTIL_HPP
#define AZALEA_GLADUTIL_HPP

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace azalea::util {
    GladGLContext* createGLADContext( GLFWwindow* window );
    void destroyGLADContext( GladGLContext* context );
}

#endif// AZALEA_GLADUTIL_HPP
