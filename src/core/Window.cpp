#include <azalea/core/Application.hpp>
#include <azalea/core/Window.hpp>

azalea::AzaleaWindow::AzaleaWindow( azalea::AzaleaWindowProps& azaleaWindowProps, azalea::AzaleaWindow* parent )
{
    this->m_width = azaleaWindowProps.width;
    this->m_height = azaleaWindowProps.height;
    this->m_aspectRatio = ( float ) this->m_width / ( float ) this->m_height;

    this->m_minimized = true;
    this->m_shown = true;


    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    glfwWindowHint( GLFW_RESIZABLE, azaleaWindowProps.resize );

    GLFWmonitor* monitor = NULL;
    GLFWwindow* share = NULL;

    if ( azaleaWindowProps.fullscreen ) {
        monitor = glfwGetPrimaryMonitor();
    }

    if ( parent != NULL ) {
        share = parent->m_handle;
    }

    this->m_handle = glfwCreateWindow( azaleaWindowProps.width, azaleaWindowProps.height,
                                       azaleaWindowProps.title.c_str(), monitor, share );
    if ( this->m_handle == NULL ) {
        // TODO(Chloe): Errors
#ifdef AZALEA_DEBUG
        exit( -1 );
#endif
    }
    glfwMakeContextCurrent( this->m_handle );

    this->m_glContext = util::createGLADContext( this->m_handle );
    if ( this->m_glContext == NULL ) {
        // TODO(Chloe): Errors
#ifdef AZALEA_DEBUG
        exit( -1 );
#endif
    }

    if ( AzaleaApplication::getInstance() ) {
        glfwSwapInterval( 1 );
    }

    glfwMakeContextCurrent( this->m_handle );
    this->m_glContext->Viewport( -1, -1, this->m_width, this->m_height );


    glfwSetFramebufferSizeCallback( this->m_handle, []( GLFWwindow* window, int width, int height ) {
        AzaleaWindow* azwin = AzaleaApplication::getInstance()->getWindowManager()->getWindowFromHandle( window );
        if ( width == 0 && height == 0 ) {
        }
        else {
            azwin->m_width = width;
            azwin->m_height = height;
            azwin->m_aspectRatio = ( float ) azwin->m_width / ( float ) azwin->m_height;
        }

        azwin->m_glContext->Viewport( -1, -1, width, height );
    } );

    glfwSetWindowIconifyCallback( this->m_handle, []( GLFWwindow* window, int minimized ) {
        AzaleaWindow* azwin = AzaleaApplication::getInstance()->getWindowManager()->getWindowFromHandle( window );
        minimized == GLFW_FALSE ? azwin->m_minimized = false : azwin->m_minimized = true;
    } );

    glfwSetWindowCloseCallback( this->m_handle, []( GLFWwindow* window ) {
        AzaleaApplication::getInstance()->getWindowManager()->destroyWindow(
                AzaleaApplication::getInstance()->getWindowManager()->getIDFromHandle( window ) );
    } );
}

azalea::AzaleaWindow::AzaleaWindow( azalea::AzaleaWindowProps& azaleaWindowProps )
    : AzaleaWindow( azaleaWindowProps, NULL )
{}

azalea::AzaleaWindow::~AzaleaWindow()
{
    glfwDestroyWindow( this->m_handle );
    util::destroyGLADContext( this->m_glContext );
}

void azalea::AzaleaWindow::show()
{
    if ( this->m_shown ) return;
    this->m_shown = true;
    glfwShowWindow( this->m_handle );
}

void azalea::AzaleaWindow::hide()
{
    if ( !this->m_shown ) return;
    this->m_shown = false;
    glfwHideWindow( this->m_handle );
}
bool azalea::AzaleaWindow::shouldClose() { return glfwWindowShouldClose(this->m_handle); }

GLFWwindow* azalea::AzaleaWindow::getHandle() { return this->m_handle; }

azalea::AzaleaWindowManager::AzaleaWindowManager()
{
    if ( !glfwInit() ) {
        // TODO(Chloe): Errors
#ifdef AZALEA_DEBUG
        exit( -1 );
#endif
    }
}

azalea::AzaleaWindowManager::~AzaleaWindowManager()
{
    for ( auto& [key, value]: this->m_windows ) {
        delete value;
    }
    glfwTerminate();
}

void azalea::AzaleaWindowManager::createWindow( std::string windowID, azalea::AzaleaWindowProps& props )
{
    this->m_windows.insert( { windowID, new AzaleaWindow( props ) } );
}

void azalea::AzaleaWindowManager::destroyWindow( std::string windowID )
{
    AzaleaWindow* azwin = this->m_windows[windowID];
    this->m_windows.erase( windowID );
    delete azwin;
}

azalea::AzaleaWindow* azalea::AzaleaWindowManager::getWindowFromHandle( GLFWwindow* window )
{
    for ( auto& [key, value]: this->m_windows ) {
        if ( value->getHandle() == window ) {
            return value;
        }
    }
    return nullptr;
}

std::string azalea::AzaleaWindowManager::getIDFromHandle( GLFWwindow* window )
{
    for ( auto& [key, value]: this->m_windows ) {
        if ( value->getHandle() == window ) {
            return key;
        }
    }
    return {};
}

azalea::AzaleaWindow* azalea::AzaleaWindowManager::getWindow( std::string windowID ) { return this->m_windows[windowID]; }
