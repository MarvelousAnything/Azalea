#ifndef AZALEA_WINDOW_HPP
#define AZALEA_WINDOW_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include <azalea/core/Events.hpp>

namespace azalea {

    struct WindowProps
    {
        uint32_t width = 720;
        uint32_t height = 720;

        const std::string& title;

        bool vsync = true;
    };

    class AzaleaWindow {
    public:
        AzaleaWindow( WindowProps& windowProps );
        ~AzaleaWindow();

        void setWindowSize( uint32_t width, uint32_t height );

        float getAspectRatio();
        bool isMinimized();

        operator GLFWwindow*();

    private:
        uint32_t m_width;
        uint32_t m_height;

        float m_aspectRatio;

        bool m_minimized;
        bool m_vsync;

        GLFWwindow* m_glfwWindow;
    };

}// namespace azalea

#endif// AZALEA_WINDOW_HPP
