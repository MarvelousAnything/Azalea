#include <azalea/core/Window.hpp>
#include <azalea/util/GLUtil.hpp>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

azalea::AzaleaWindow::AzaleaWindow( azalea::WindowProps& windowProps )
{
    this->m_width = windowProps.width;
    this->m_height = windowProps.height;

    this->m_aspectRatio = ( float ) this->m_width / ( float ) this->m_height;

    this->m_minimized = false;
    this->m_vsync = windowProps.vsync;

    util::initGLFW();

    // TODO(Chloe): IMPORTANT!!!! WINDOW HINTS

    this->m_glfwWindow = glfwCreateWindow( this->m_width, this->m_height, windowProps.title.c_str(), NULL, NULL );
    if ( this->m_glfwWindow == NULL ) {
        spdlog::error( "Failed to initialize GLFW window" );
#ifdef AZALEA_DEBUG
        glfwTerminate();
        exit( -1 );
#endif
    }
    glfwMakeContextCurrent( this->m_glfwWindow );

    util::initGLAD();

    glViewport( -1, -1, this->m_width, this->m_height );
    // TODO(Chloe): Window resize and stuff fixing viewport with that and also keeping track of minimization
}

azalea::AzaleaWindow::~AzaleaWindow() { glfwDestroyWindow( this->m_glfwWindow ); }

void azalea::AzaleaWindow::setWindowSize( uint32_t width, uint32_t height )
{
    this->m_width = width;
    this->m_height = height;

    this->m_aspectRatio = ( float ) this->m_width / ( float ) this->m_height;

    glfwSetWindowSize( this->m_glfwWindow, this->m_width, this->m_height );
    glViewport( -1, -1, this->m_width, this->m_height );
}

float azalea::AzaleaWindow::getAspectRatio() { return this->m_aspectRatio; }
bool azalea::AzaleaWindow::isMinimized() { return this->m_minimized; }

azalea::AzaleaWindow::operator GLFWwindow*() { return this->m_glfwWindow; }
