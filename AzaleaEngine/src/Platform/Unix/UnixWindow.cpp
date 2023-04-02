#include <utility>

#include <GL/glew.h>

#include "Azalea/Platform/Unix//UnixWindow.hpp"
#include "Azalea/Platform/Unix/UnixPlatformUtil.hpp"
#include "Azalea/Core/Macros.hpp"

namespace azalea::window {
    UnixWindow::UnixWindow(UnixWindow* window, AzaleaWindowOptions opts)
    : AzaleaWindow(window, std::move(opts)) {
        auto* platformInfo = (UnixPlatformInfo*) azalea::AzaleaApplication::get()->getPlatformInfo();
        if (!platformInfo->glfwInitialized) {
            platformInfo->glfwInitialized = true;
            glfwInit();

            // Set some window hints
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

            m_window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), nullptr, nullptr);

            if (!m_window) {
                glfwTerminate();
                AZALEA_LOG_GENERIC_ERROR("Failed to create the Azalea Window\n");
            }

            glfwMakeContextCurrent(m_window);

            if (glewInit() != GLEW_OK) {
                AZALEA_LOG_GENERIC_ERROR("Failed to initialize GLEW\n");
            }
        }
    }

    UnixWindow::UnixWindow(AzaleaWindowOptions opts) : UnixWindow(nullptr, std::move(opts)) {}

    UnixWindow::~UnixWindow() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void UnixWindow::show() {
        glfwShowWindow(m_window);
        m_isShowing = true;
    }

    void UnixWindow::hide() {
        glfwHideWindow(m_window);
        m_isShowing = false;
    }

    void UnixWindow::poll() {
        glfwPollEvents();
    }

    void UnixWindow::maximizeWindow() {
        glfwMaximizeWindow(m_window);
    }

    void UnixWindow::requestAttention() {
        glfwRequestWindowAttention(m_window);
    }

    void UnixWindow::setWidth(int32_t width) {
        glfwSetWindowAspectRatio(m_window, width, getHeight());
    }

    void UnixWindow::setHeight(int32_t height) {
        glfwSetWindowAspectRatio(m_window, getWidth(), height);
    }

    void UnixWindow::setWindowMode(AzaleaWindowMode mode) {
        // TODO: Implement this
    }

    void UnixWindow::setTitle(std::string title) {
        AzaleaWindow::setTitle(title);
        glfwSetWindowTitle(m_window, title.c_str());
    }

     void *UnixWindow::getNativeWindowHandle() {
        return m_window;
    }
}