#ifndef AZALEA_WINDOWSWINDOW_HPP
#define AZALEA_WINDOWSWINDOW_HPP

#include <Azalea/Window/Window.hpp>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winuser.h>

namespace azalea::window {

    class WindowsWindow : public AzaleaWindow {
        friend class AzaleaWindow;

    public:
        WindowsWindow( AzaleaWindowOptions opts );
        ~WindowsWindow() override;// I have no idea if this is a good idea...

        void show() override;
        void hide() override;

        void setWidth( int32_t width ) override;
        void setHeight( int32_t height ) override;
        void setWindowMode( AzaleaWindowMode mode ) override;
        void setTitle( std::string title ) override;

    private:
        WindowsWindow( AzaleaWindow* parent, AzaleaWindowOptions opts );

        static WNDCLASS s_windowClass;
        static LRESULT CALLBACK s_windowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
        static HINSTANCE s_hinstance;

        HWND m_handle;
    };

    int32_t windowModeToWindowsStyle( AzaleaWindowMode mode );

}// namespace azalea::window

#endif// AZALEA_WINDOWSWINDOW_HPP
