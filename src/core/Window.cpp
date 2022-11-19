#include <azalea/core/Window.hpp>
#include <azalea/util/GLUtil.hpp>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

namespace {
    azalea::AzaleaWindow* s_instance = nullptr;
}

azalea::AzaleaWindow::AzaleaWindow( azalea::WindowProps& windowProps )
{
    this->m_width = windowProps.width;
    this->m_height = windowProps.height;

    this->m_aspectRatio = ( float ) this->m_width / ( float ) this->m_height;

    this->m_minimized = false;
    this->m_vsync = windowProps.vsync;

    util::initGLFW();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

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

    if (this->m_vsync) {
        glfwSwapInterval( 1 );
    }

    glViewport( -1, -1, this->m_width, this->m_height );

    glfwSetWindowSizeCallback(this->m_glfwWindow, [](GLFWwindow* glfwWindow, int32_t newWidth, int32_t newHeight){
        s_instance->m_width = newWidth;
        s_instance->m_height = newHeight;

        s_instance->m_aspectRatio = ( float ) s_instance->m_width / ( float ) s_instance->m_height;
        glViewport( -1, -1, s_instance->m_width, s_instance->m_height );
    });

    glfwShowWindow(this->m_glfwWindow);
    this->m_shown = true;
    s_instance = this;
}

azalea::AzaleaWindow::~AzaleaWindow() { glfwDestroyWindow( this->m_glfwWindow ); }

void azalea::AzaleaWindow::show()
{
    glfwShowWindow(this->m_glfwWindow);
    this->m_shown = true;
}

void azalea::AzaleaWindow::hide()
{
    glfwHideWindow(this->m_glfwWindow);
    this->m_shown = false;
}

void azalea::AzaleaWindow::forceFocus()
{
    glfwFocusWindow(this->m_glfwWindow);
}

void azalea::AzaleaWindow::requestAttention()
{
    glfwRequestWindowAttention(this->m_glfwWindow);
}

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

bool azalea::AzaleaWindow::shouldClose() { return glfwWindowShouldClose(this->m_glfwWindow); }

azalea::AzaleaWindow::operator GLFWwindow*() { return this->m_glfwWindow; }
