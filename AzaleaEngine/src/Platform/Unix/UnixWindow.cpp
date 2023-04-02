#include <utility>

#include "Azalea/Platform/Unix//UnixWindow.hpp"
#include "Azalea/Platform/Unix/UnixPlatformUtil.hpp"

namespace azalea::window {
    UnixWindow::UnixWindow(UnixWindow* window, AzaleaWindowOptions opts)
    : AzaleaWindow(window, std::move(opts)) {
        auto* platformInfo = (UnixPlatformInfo*) azalea::AzaleaApplication::get()->getPlatformInfo();
        if (!platformInfo->glfwInitialized) {
            platformInfo->glfwInitialized = true;
            glfwInit();

            // Set some window hints
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

            m_window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), nullptr, nullptr);

            if (!m_window) {
                glfwTerminate();
                azalea::AzaleaApplication::get()->getLogger()->error(LogErrorType::GENERIC_ERROR, "Failed to create GLFW window");
            }
        }
    }
}