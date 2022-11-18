#ifndef AZALEA_ENTRY_HPP
#define AZALEA_ENTRY_HPP

#include <azalea/core/Application.hpp>

extern azalea::AzaleaApplication* azalea::instantiateAzaleaApplication( int32_t argc, const char** argv );

int main( int argc, const char** argv )
{
    auto* game = azalea::instantiateAzaleaApplication( argc, argv );
    game->run();
    delete game;
}

#endif// AZALEA_ENTRY_HPP
