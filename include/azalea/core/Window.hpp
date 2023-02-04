#ifndef AZALEA_WINDOW_HPP
#define AZALEA_WINDOW_HPP

#include <map>
#include <string>

#include <azalea/util/GladUtil.hpp>

namespace azalea {

    struct AzaleaWindowProps
    {
        uint32_t width;
        uint32_t height;

        bool fullscreen = false;
        bool resize = true;

        std::string title;
    };

    class AzaleaWindow {
    public:
        AzaleaWindow( AzaleaWindowProps& azaleaWindowProps );
        AzaleaWindow( AzaleaWindowProps& azaleaWindowProps, AzaleaWindow* parent );

        ~AzaleaWindow();

        void show();
        void hide();

        bool shouldClose();

        GLFWwindow* getHandle();

    private:
        uint32_t m_width;
        uint32_t m_height;
        float m_aspectRatio;

        bool m_minimized;
        bool m_shown;

        GLFWwindow* m_handle;
        GladGLContext* m_glContext;
    };

    class AzaleaWindowManager {
    public:
        AzaleaWindowManager();
        ~AzaleaWindowManager();

        void createWindow( std::string windowID, AzaleaWindowProps& props );

        void destroyWindow( std::string windowID );

        AzaleaWindow* getWindow( std::string windowID );

        std::string getIDFromHandle( GLFWwindow* window );
        AzaleaWindow* getWindowFromHandle( GLFWwindow* window );

    private:
        std::map<std::string, AzaleaWindow*> m_windows;
    };

}// namespace azalea

#endif// AZALEA_WINDOW_HPP
