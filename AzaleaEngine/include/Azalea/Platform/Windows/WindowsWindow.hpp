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
        ~WindowsWindow();

        void show() override;
        void hide() override;

    private:
        WindowsWindow( AzaleaWindow* parent, AzaleaWindowOptions opts );

        static WNDCLASS s_windowClass;
        static LRESULT CALLBACK s_windowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
        static HINSTANCE s_hinstance;

        HWND m_handle;
    };

}// namespace azalea::window

#endif// AZALEA_WINDOWSWINDOW_HPP
