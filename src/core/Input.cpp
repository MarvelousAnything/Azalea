#include <GLFW/glfw3.h>
#include <azalea/core/Input.hpp>

bool azalea::isKeyPressed( azalea::KeyCode keyCode )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetKey( window, keyCode ) == GLFW_PRESS;
}

bool azalea::isKeyDown( azalea::KeyCode keyCode )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetKey( window, keyCode ) == GLFW_REPEAT;
}

bool azalea::isKeyReleased( azalea::KeyCode keyCode )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetKey( window, keyCode ) == GLFW_RELEASE;
}


bool azalea::isMouseButtonPressed( azalea::MouseButton mouseButton )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetMouseButton( window, mouseButton ) == GLFW_RELEASE;
}

bool azalea::isMouseButtonDown( azalea::MouseButton mouseButton )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetMouseButton( window, mouseButton ) == GLFW_RELEASE;
}

bool azalea::isMouseButtonReleased( azalea::MouseButton mouseButton )
{
    // TODO(Chloe): Fix me
    GLFWwindow* window;
    return glfwGetMouseButton( window, mouseButton ) == GLFW_RELEASE;
}