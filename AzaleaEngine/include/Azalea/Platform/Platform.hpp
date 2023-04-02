#ifndef AZALEA_PLATFORM_HPP
#define AZALEA_PLATFORM_HPP

#if not defined AZALEA_PLATFORM_WINDOWS || not defined AZALEA_PLATFORM_LINUX || not defined AZALEA_PLATFORM_MACOS

#if defined WIN32 || defined WIN64
#define AZALEA_PLATFORM_WINDOWS
#elif defined __linux__
#define AZALEA_PLATFORM_LINUX
#elif defined __APPLE__
#define AZALEA_PLATFORM_MACOS
#else
#error "Unknown or Unsupported Platform"
#endif// If defined WIN32 ...

#endif// If not defined AZALEA_PLATFORM_WINDOWS ...

#ifdef AZALEA_PLATFORM_WINDOWS
// Windows Includes

#include <Azalea/Platform/Windows/WindowsWindow.hpp>
#include <Azalea/Platform/Windows/WindowsPlatformUtil.hpp>

#endif

#endif// AZALEA_PLATFORM_HPP
