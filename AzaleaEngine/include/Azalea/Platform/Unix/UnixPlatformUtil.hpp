#ifndef AZALEA_UNIXPLATFORMUTIL_HPP
#define AZALEA_UNIXPLATFORMUTIL_HPP

#include <Azalea/Core/Application.hpp>

struct UnixPlatformInfo : azalea::PlatformInfo {
    bool glfwInitialized = false;
};

#endif //AZALEA_UNIXPLATFORMUTIL_HPP
