#include <Azalea/Platform/Windows/WindowsWindow.hpp>

#define AZALEA_MAIN_CLASS_NAME "AzaleaWindow"

WNDCLASS azalea::window::WindowsWindow::s_windowClass = { 0 };
HINSTANCE azalea::window::WindowsWindow::s_hinstance = nullptr;
LRESULT CALLBACK azalea::window::WindowsWindow::s_windowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    return 0;
}

azalea::window::WindowsWindow::WindowsWindow( azalea::window::AzaleaWindow* parent,
                                              azalea::window::AzaleaWindowOptions opts )
    : AzaleaWindow( parent, opts )
{
    if ( s_hinstance == nullptr ) {
        s_hinstance = GetModuleHandle( nullptr );

        s_windowClass = { 0 };
        s_windowClass.style = CS_BYTEALIGNWINDOW | CS_HREDRAW | CS_VREDRAW;
        s_windowClass.lpfnWndProc = DefWindowProc;
        s_windowClass.cbClsExtra = 0;
        s_windowClass.cbWndExtra = 0;
        s_windowClass.hInstance = s_hinstance;
        s_windowClass.hIcon = nullptr;
        s_windowClass.hCursor = LoadCursor( NULL, IDC_ARROW );
        s_windowClass.hbrBackground = NULL;
        s_windowClass.lpszMenuName = 0;
        s_windowClass.lpszClassName = AZALEA_MAIN_CLASS_NAME;

        if ( !RegisterClass( &s_windowClass ) ) {
            printf( "Error when creating window class\n" );
        }
    }

    HWND parentHandle = nullptr;
    if ( parent != nullptr ) {
        parentHandle = ( ( WindowsWindow* ) parent )->m_handle;
    }
    this->m_handle =
            CreateWindow( ( LPSTR ) AZALEA_MAIN_CLASS_NAME, opts.title.c_str(),
                          WS_OVERLAPPEDWINDOW /* This might need changing depending on what preferences the
                                                 user has in terms of winodw mode */
                          ,
                          CW_USEDEFAULT, CW_USEDEFAULT, opts.width, opts.height, parentHandle, NULL, s_hinstance, NULL );
    if ( this->m_handle == nullptr ) {
        // error
        printf( "Window Failed to create\n" );
        printf( "%lu\n", GetLastError() );
    }
}
void azalea::window::WindowsWindow::show() { ShowWindow( this->m_handle, SW_NORMAL ); }

void azalea::window::WindowsWindow::hide() { ShowWindow( this->m_handle, SW_HIDE ); }

azalea::window::WindowsWindow::WindowsWindow( azalea::window::AzaleaWindowOptions opts ) : WindowsWindow( nullptr, opts )
{}
