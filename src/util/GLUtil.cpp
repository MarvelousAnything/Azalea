#include <azalea/util/GLUtil.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

namespace {
    bool _glfwInit = false;
    bool _gladInit = false;
}// namespace

void azalea::util::initGLFW()
{
    if ( _glfwInit ) {
        return;
    }

    if ( !glfwInit() ) {
        spdlog::error( "Failed to initialize GLFW" );
#ifdef AZALEA_DEBUG
        exit( -1 );
#endif
        return;
    }

    _glfwInit = true;
}

void azalea::util::initGLAD()
{
    if ( _gladInit ) {
        return;
    }

    if ( !gladLoadGL( glfwGetProcAddress ) ) {
        spdlog::error( "Failed to initialize GLAD" );
#ifdef AZALEA_DEBUG
        glfwTerminate();
        exit( -1 );
#endif
    }

    _gladInit = true;
}