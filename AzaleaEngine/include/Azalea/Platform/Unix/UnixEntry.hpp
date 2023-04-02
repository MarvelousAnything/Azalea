#ifndef AZALEA_UNIXENTRY_HPP
#define AZALEA_UNIXENTRY_HPP

#include <Azalea/Platform/Unix/UnixPlatformUtil.hpp>

int main(int argc, char **argv)
{
    auto *gayme = azalea::instantiateGame(argc, argv);

    auto *info = new UnixPlatformInfo();
    info->platformName = "Unix";
    info->glfwInitialized = false;

    gayme->setPlatformInfo(info);

    gayme->run();
    delete gayme;

    return 0;
}

#endif //AZALEA_UNIXENTRY_HPP
