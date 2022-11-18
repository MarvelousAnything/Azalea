#ifndef AZALEA_KEY_HPP
#define AZALEA_KEY_HPP

#include <azalea/core/Key.hpp>
#include <azalea/core/Mouse.hpp>

namespace azalea {

    bool isKeyPressed( KeyCode keyCode );
    bool isKeyDown( KeyCode keyCode );
    bool isKeyReleased( KeyCode keyCode );

    bool isMouseButtonPressed( MouseButton mouseButton );
    bool isMouseButtonDown( MouseButton mouseButton );
    bool isMouseButtonReleased( MouseButton mouseButton );

}// namespace azalea


#endif// AZALEA_KEY_HPP
