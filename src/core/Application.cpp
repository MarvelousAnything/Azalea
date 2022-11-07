#include <azalea/core/Application.hpp>
#include <iostream>

azalea::AzaleaApplication* azalea::AzaleaApplication::s_instance = nullptr;

azalea::AzaleaApplication::AzaleaApplication( azalea::ApplicationProps& applicationProps )
    : m_applicationProps( applicationProps )
{
    azalea::AzaleaApplication::s_instance = this;
}

azalea::AzaleaApplication::~AzaleaApplication()
{
}

azalea::AzaleaApplication* azalea::AzaleaApplication::getInstance() { return AzaleaApplication::s_instance; }

void azalea::AzaleaApplication::run()
{
    std::cout << "Hello, World!\n";
}
