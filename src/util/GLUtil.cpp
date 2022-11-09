#include <azalea/util/GLUtil.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

namespace {
    bool _glfwInit = false;
}

void azalea::util::initGLFW()
{
    if (_glfwInit) {
        return;
    }

    if (!glfwInit()) {
        spdlog::error("Failed to initialize GLFW");
#ifdef AZALEA_EXIT_IF_ERR
      exit(-1);
#endif
      return;
    }

    _glfwInit = true;
}