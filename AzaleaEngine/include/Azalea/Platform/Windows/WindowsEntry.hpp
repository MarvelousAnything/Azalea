#ifndef AZALEA_WINDOWSENTRY_HPP
#define AZALEA_WINDOWSENTRY_HPP

#include <Azalea/Platform/Windows/WindowsPlatformUtil.hpp>

extern azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv );

int CALLBACK WinMain(HINSTANCE hinstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int showCmdLine)
{
    auto* gayme = azalea::instantiateGame(__argc, __argv);

    auto* info = new WindowsPlatformInfo();
    info->platformName = "Windows";
    info->registeredWindowClass = false;
    info->hinstance = hinstance;
    info->showCmdLine = showCmdLine;

    gayme->setPlatformInfo(info);

    gayme->run();
    delete gayme;

    return 0;
}

#endif// AZALEA_WINDOWSENTRY_HPP
