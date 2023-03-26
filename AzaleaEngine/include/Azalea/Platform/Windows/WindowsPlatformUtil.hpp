#ifndef AZALEA_WINDOWSPLATFORMUTIL_HPP
#define AZALEA_WINDOWSPLATFORMUTIL_HPP

#include <Azalea/Core/Application.hpp>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winuser.h>

struct WindowsPlatformInfo : azalea::PlatformInfo {
    HINSTANCE hinstance{};
    int32_t showCmdLine{};
    bool registeredWindowClass = false;
};

#endif// AZALEA_WINDOWSPLATFORMUTIL_HPP
