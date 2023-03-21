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

    int32_t windowWidth = opts.width;
    int32_t windowHeight = opts.height;

    if ( opts.windowMode == AzaleaWindowMode::BORDERLESS_WINDOW ) {
        // this is done to calculate the window size for borderless window since that is how it works :)
        windowWidth = GetSystemMetrics( SM_CXSCREEN );
        windowHeight = GetSystemMetrics( SM_CYSCREEN );
    }

    this->m_handle = CreateWindow( ( LPSTR ) AZALEA_MAIN_CLASS_NAME, opts.title.c_str(),
                                   windowModeToWindowsStyle( opts.windowMode ) /* This might need changing depending on
                                                            what preferences the user has in terms of winodw mode */
                                   ,
                                   CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight, parentHandle, NULL,
                                   s_hinstance, NULL );
    if ( this->m_handle == nullptr ) {
        // error
        printf( "Window Failed to create\n" );
        printf( "%lu\n", GetLastError() );
    }
}

azalea::window::WindowsWindow::~WindowsWindow()
{
    AzaleaWindow::~AzaleaWindow();
    DestroyWindow( this->m_handle );
}

void azalea::window::WindowsWindow::show()
{

    ShowWindow( this->m_handle, SW_NORMAL );
    UpdateWindow( this->m_handle );
}

void azalea::window::WindowsWindow::hide() { ShowWindow( this->m_handle, SW_HIDE ); }

azalea::window::WindowsWindow::WindowsWindow( azalea::window::AzaleaWindowOptions opts ) : WindowsWindow( nullptr, opts )
{}

void azalea::window::WindowsWindow::setWidth( int32_t width )
{
    AzaleaWindow::setWidth( width );
    SetWindowPos( this->m_handle, nullptr, 0, 0, width, this->getHeight(), SWP_NOMOVE | SWP_SHOWWINDOW );
}

void azalea::window::WindowsWindow::setHeight( int32_t height )
{
    AzaleaWindow::setHeight( height );
    SetWindowPos( this->m_handle, nullptr, 0, 0, this->getWidth(), height, SWP_NOMOVE | SWP_SHOWWINDOW );
}

void azalea::window::WindowsWindow::setWindowMode( azalea::window::AzaleaWindowMode mode )
{
    AzaleaWindow::setWindowMode( mode );
    SetWindowLongPtr( this->m_handle, GWL_STYLE, windowModeToWindowsStyle( mode ) );
    SetWindowPos( this->m_handle, HWND_TOPMOST, 100, 100, this->getWidth(), this->getHeight(), SWP_SHOWWINDOW );
}
void azalea::window::WindowsWindow::setTitle( std::string title )
{
    AzaleaWindow::setTitle( title );
    SetWindowText( this->m_handle, title.c_str() );
}

void azalea::window::WindowsWindow::poll()
{
    MSG msg;
    if ( GetMessage( &msg, this->m_handle, NULL, NULL ) > 0 ) {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
}
void* azalea::window::WindowsWindow::getNativeWindowHandle() { return ( void* ) this->m_handle; }

int32_t azalea::window::windowModeToWindowsStyle( azalea::window::AzaleaWindowMode mode )
{
    switch ( mode ) {
        case AzaleaWindowMode::FULLSCREEN:
            return WS_POPUP;
        case AzaleaWindowMode::BORDERLESS_WINDOW:
            return WS_MAXIMIZE;
        case AzaleaWindowMode::WINDOWED:
            return WS_OVERLAPPEDWINDOW;
    }
    return 0;
}