#ifndef AZALEA_WINDOWSWINDOW_HPP
#define AZALEA_WINDOWSWINDOW_HPP

#include <Azalea/Platform/Windows/WindowsPlatformUtil.hpp>
#include <Azalea/Window/Window.hpp>

// HACK: I need to get the application instance, but it's a cyclic include soooo
namespace azalea {
    class AzaleaApplication;
}

namespace azalea::window {
    class WindowsWindow : public AzaleaWindow {
        friend class AzaleaWindow;

    public:
        WindowsWindow( AzaleaWindowOptions opts );
        ~WindowsWindow() override;

        void show() override;
        void hide() override;
        void poll() override;
        void maximizeWindow() override;
        void requestAttention() override;

        void setWidth( int32_t width ) override;
        void setHeight( int32_t height ) override;
        void setWindowMode( AzaleaWindowMode mode ) override;

        void setTitle( std::string title ) override;

        void* getNativeWindowHandle() override;

    private:
        WindowsWindow( WindowsWindow* window, AzaleaWindowOptions options );

        void m_internalApplyWindowForm( AzaleaWindowMode mode, bool startup );

        HWND m_windowHandle;
    };
}// namespace azalea::window

#include <Azalea/Core/Application.hpp>

#endif// AZALEA_WINDOWSWINDOW_HPP
