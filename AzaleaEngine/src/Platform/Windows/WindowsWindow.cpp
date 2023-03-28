#include <Azalea/Platform/Windows/WindowsPlatformUtil.hpp>
#include <Azalea/Platform/Windows/WindowsWindow.hpp>

#define AZALEA_CLASS_NAME "AzaleaWindowClass"

azalea::window::WindowsWindow::WindowsWindow( azalea::window::WindowsWindow* window,
                                              azalea::window::AzaleaWindowOptions opts )
    : AzaleaWindow( window, opts )
{
    auto* platformInfo = ( WindowsPlatformInfo* ) azalea::AzaleaApplication::get()->getPlatformInfo();
    if ( !platformInfo->registeredWindowClass ) {
        WNDCLASS windowClass = { 0 };
        windowClass.style = CS_BYTEALIGNWINDOW | CS_HREDRAW | CS_VREDRAW;
        windowClass.lpfnWndProc = DefWindowProc;
        windowClass.cbClsExtra = 0;
        windowClass.cbWndExtra = 0;
        windowClass.hInstance = platformInfo->hinstance;
        windowClass.hIcon = nullptr;
        windowClass.hCursor = LoadCursor( nullptr, IDC_ARROW );
        windowClass.hbrBackground = nullptr;
        windowClass.lpszMenuName = nullptr;
        windowClass.lpszClassName = AZALEA_CLASS_NAME;

        if ( !RegisterClass( &windowClass ) ) {
            azalea::AzaleaApplication::get()->getLogger()->error( LogErrorType::GENERIC_ERROR,
                                                                  "Failed to create the Azalea Window Class\n" );
        }
        else {
            platformInfo->registeredWindowClass = true;
        }
    }
    HWND parentWindowHandle = nullptr;
    if ( window ) {
        parentWindowHandle = window->m_windowHandle;
    }


    this->m_windowHandle =
            CreateWindowEx( 0, AZALEA_CLASS_NAME, opts.title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                            opts.width, opts.height, parentWindowHandle, nullptr, platformInfo->hinstance, nullptr );

    this->m_internalApplyWindowForm( opts.windowMode, true );

    if ( this->m_windowHandle == nullptr ) {
        azalea::AzaleaApplication::get()->getLogger()->error(
                LogErrorType::GENERIC_ERROR, "Failed to create the Azalea Window. Error Code: %lu\n", GetLastError() );
    }
}

azalea::window::WindowsWindow::WindowsWindow( AzaleaWindowOptions opts ) : WindowsWindow( nullptr, opts ) {}

azalea::window::WindowsWindow::~WindowsWindow()
{
    AzaleaWindow::~AzaleaWindow();
    DestroyWindow( this->m_windowHandle );
}

void azalea::window::WindowsWindow::maximizeWindow()
{
    MONITORINFO info = { sizeof( info ) };
    GetMonitorInfo( MonitorFromWindow( this->m_windowHandle, MONITOR_DEFAULTTONEAREST ), &info );

    RECT rect = info.rcWork;

    int32_t windowStyle = GetWindowLong( this->m_windowHandle, GWL_STYLE );
    windowStyle |= WS_MAXIMIZE;
    SetWindowLong( this->m_windowHandle, GWL_STYLE, windowStyle );

    SetWindowPos( this->m_windowHandle, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
                  SWP_NOACTIVATE | SWP_NOZORDER | SWP_FRAMECHANGED );
}

void azalea::window::WindowsWindow::show() { ShowWindow( this->m_windowHandle, SW_SHOWNA ); }

void azalea::window::WindowsWindow::m_internalApplyWindowForm( azalea::window::AzaleaWindowMode mode, bool startup )
{
    switch ( mode ) {

        case AzaleaWindowMode::FULLSCREEN:
            SetWindowLong( this->m_windowHandle, GWL_STYLE, WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS );
            SetWindowPos( this->m_windowHandle, HWND_TOPMOST, 0, 0, GetSystemMetrics( SM_CXSCREEN ),
                          GetSystemMetrics( SM_CYSCREEN ), SWP_FRAMECHANGED );
            break;
        case AzaleaWindowMode::WINDOWED_FULLSCREEN:
            SetWindowLong( this->m_windowHandle, GWL_STYLE, WS_POPUP | WS_VISIBLE );
            SetWindowPos( this->m_windowHandle, HWND_TOPMOST, 0, 0, GetSystemMetrics( SM_CXSCREEN ),
                          GetSystemMetrics( SM_CYSCREEN ), SWP_FRAMECHANGED );
            break;
        case AzaleaWindowMode::WINDOWED:
            if ( startup ) {
                break;
            }
            SetWindowLong( this->m_windowHandle, GWL_STYLE, WS_OVERLAPPEDWINDOW );
            SetWindowPos( this->m_windowHandle, HWND_TOPMOST, CW_USEDEFAULT, CW_USEDEFAULT, this->getWidth(),
                          this->getHeight(), SWP_FRAMECHANGED );
    }
}

void azalea::window::WindowsWindow::poll()
{
    MSG message;
    if ( GetMessage( &message, this->m_windowHandle, 0, 0 ) <= 0 ) {
        this->m_shouldClose = true;
    }
    TranslateMessage( &message );
    DispatchMessage( &message );
}

void azalea::window::WindowsWindow::hide() { ShowWindow( this->m_windowHandle, SW_HIDE ); }

void azalea::window::WindowsWindow::setWindowMode( azalea::window::AzaleaWindowMode mode )
{
    AzaleaWindow::setWindowMode( mode );
    this->m_internalApplyWindowForm( mode, false );
}

void azalea::window::WindowsWindow::setWidth( int32_t width )
{
    AzaleaWindow::setWidth( width );
    SetWindowPos(this->m_windowHandle, 0, 0, width, this->getHeight(), SWP_NOMOVE, SWP_FRAMECHANGED );
}

void azalea::window::WindowsWindow::setHeight( int32_t height )
{
    AzaleaWindow::setHeight( height );
    SetWindowPos(this->m_windowHandle, 0, 0, this->getWidth(), height, SWP_NOMOVE, SWP_FRAMECHANGED );
}

void azalea::window::WindowsWindow::setTitle( std::string title )
{
    AzaleaWindow::setTitle( title );
    SetWindowText(this->m_windowHandle, title.c_str());
}

void* azalea::window::WindowsWindow::getNativeWindowHandle()
{
    return this->m_windowHandle;
}
