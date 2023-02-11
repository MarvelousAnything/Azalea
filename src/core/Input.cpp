#include <azalea/core/Application.hpp>
#include <azalea/core/Input.hpp>

bool azalea::getKey( AzaleaWindow* window, KeyCode keyCode )
{
    return glfwGetKey( window->getHandle(), keyCode ) == GLFW_PRESS || GLFW_REPEAT;
}

bool azalea::getKey( KeyCode keyCode )
{
    return getKey( AzaleaApplication::getInstance()->getWindowManager()->getWindow( "main" ), keyCode );
}

bool azalea::isKeyUp( KeyCode keyCode ) { return !getKey( keyCode ); }

bool azalea::isKeyDown( KeyCode keyCode ) { return getKey( keyCode ); }

bool azalea::getMouseButton( AzaleaWindow* window, MouseButton mouseButton )
{
    return glfwGetMouseButton( window->getHandle(), mouseButton ) == GLFW_PRESS || GLFW_REPEAT;
}

bool azalea::getMouseButton( MouseButton mouseButton )
{
    return getMouseButton( AzaleaApplication::getInstance()->getWindowManager()->getWindow( "main" ), mouseButton );
}

bool azalea::isMouseButtonUp( MouseButton mouseButton ) { return !getMouseButton( mouseButton ); }

bool azalea::isMouseButtonHeld( MouseButton mouseButton )
{
    return glfwGetMouseButton( AzaleaApplication::getInstance()->getWindowManager()->getWindow( "main" )->getHandle(),
                               mouseButton ) == GLFW_REPEAT;
}

bool azalea::isMouseButtonDown( azalea::MouseButton mouseButton )
{
    return glfwGetMouseButton( AzaleaApplication::getInstance()->getWindowManager()->getWindow( "main" )->getHandle(),
                               mouseButton ) == GLFW_PRESS;
}

void azalea::getMousePosition( AzaleaWindow* window, double* x, double* y )
{
    glfwGetCursorPos( window->getHandle(), x, y);
}

void azalea::getMousePosition( double* x, double* y )
{
    getMousePosition(AzaleaApplication::getInstance()->getWindowManager()->getWindow("main"), x, y);
}

double azalea::getMouseX( AzaleaWindow* window )
{
    double x, y;
    getMousePosition(window, &x, &y);
    return x;
}

double azalea::getMouseX()
{
    double x, y;
    getMousePosition(&x, &y);
    return x;
}

double azalea::getMouseY( AzaleaWindow* window )
{
    double x, y;
    getMousePosition(window, &x, &y);
    return y;
}

double azalea::getMouseY()
{
    double x, y;
    getMousePosition(&x, &y);
    return y;
}