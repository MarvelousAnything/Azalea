#ifndef AZALEA_UNIXWINDOW_HPP
#define AZALEA_UNIXWINDOW_HPP

#include "Azalea/Window/Window.hpp"
#include <GLFW/glfw3.h>

namespace azalea {
    class AzaleaApplication;
}

namespace azalea::window {
    class UnixWindow : public AzaleaWindow {
        friend class AzaleaWindow;

    public:
        explicit UnixWindow(AzaleaWindowOptions opts);
        ~UnixWindow() override;

        void show() override;
        void hide() override;
        void poll() override;
        void maximizeWindow() override;
        void requestAttention() override;

        void setWidth(int32_t width) override;
        void setHeight(int32_t height) override;
        void setWindowMode(AzaleaWindowMode mode) override;

        void setTitle(std::string title) override;

        void* getNativeWindowHandle() override;

    private:
        UnixWindow(UnixWindow* window, AzaleaWindowOptions options );
        GLFWwindow* m_window;
    };
}


#endif //AZALEA_UNIXWINDOW_HPP
