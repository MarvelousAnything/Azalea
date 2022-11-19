#include <azalea/core/Application.hpp>
#include <iostream>
#include <spdlog/spdlog.h>

azalea::AzaleaApplication* azalea::AzaleaApplication::s_instance = nullptr;

azalea::AzaleaApplication::AzaleaApplication( azalea::ApplicationProps& applicationProps )
    : m_applicationProps( applicationProps )
{
    spdlog::set_pattern( "[%H:%M:%S %z] [%n] %v" );
    azalea::AzaleaApplication::s_instance = this;


    WindowProps props = {.width = 720, .height = 720, .title = applicationProps.name};
    this->m_window = new AzaleaWindow(props);
}

azalea::AzaleaApplication::~AzaleaApplication()
{
    delete this->m_window;
}

azalea::AzaleaWindow* azalea::AzaleaApplication::getWindow() { return this->m_window; }

azalea::AzaleaApplication* azalea::AzaleaApplication::getInstance() { return AzaleaApplication::s_instance; }

void azalea::AzaleaApplication::run()
{
    while (!this->m_window->shouldClose()) {

        glfwPollEvents();
    }
}
