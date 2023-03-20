#ifndef AZALEA_ENTRY_HPP
#define AZALEA_ENTRY_HPP

#include <Azalea/Core/Application.hpp>

extern azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv );

int main(int argc, char** argv)
{
    auto* gamer = azalea::instantiateGame(argc, argv);
    gamer->run();
    delete gamer;

    return 0; // this actually confused me xd
}

#endif// AZALEA_ENTRY_HPP
