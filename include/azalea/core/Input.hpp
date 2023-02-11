#ifndef AZALEA_INPUT_HPP
#define AZALEA_INPUT_HPP

#include <azalea/core/Key.hpp>
#include <azalea/core/Mouse.hpp>
#include <azalea/core/Window.hpp>

namespace azalea {

    //<editor-fold desc="Key Codes">
    bool getKey( AzaleaWindow* window, KeyCode keyCode );
    bool getKey( KeyCode keyCode );

    bool isKeyUp( KeyCode keyCode );
    bool isKeyDown( KeyCode keyCode );
    //</editor-fold>

    //<editor-fold desc="Mouse Buttons">
    bool getMouseButton( AzaleaWindow* window, MouseButton mouseButton );
    bool getMouseButton( MouseButton mouseButton );

    bool isMouseButtonUp( MouseButton mouseButton );
    bool isMouseButtonHeld( MouseButton mouseButton );
    bool isMouseButtonDown( MouseButton mouseButton );
    //</editor-fold>

    //<editor-fold desc="Mouse Position">
    void getMousePosition( AzaleaWindow* window, double* x, double* y );
    void getMousePosition( double* x, double* y );

    double getMouseX( AzaleaWindow* window );
    double getMouseX();

    double getMouseY( AzaleaWindow* window );
    double getMouseY();
    //</editor-fold>

}// namespace azalea


#endif// AZALEA_INPUT_HPP
