#include <Azalea/Core/Application.hpp>

azalea::AzaleaApplication* azalea::AzaleaApplication::s_instance = nullptr;

azalea::AzaleaApplication::AzaleaApplication( std::string applicationName )
{
    this->m_name = std::move( applicationName );
    this->m_logger = new StandardOutputLogger();

    AzaleaApplication::s_instance = this;
}

azalea::AzaleaApplication::~AzaleaApplication() { delete this->m_logger; }

#include <iostream>
void azalea::AzaleaApplication::run() { std::cout << "Basic Logic\n"; }

azalea::AzaleaApplication* azalea::AzaleaApplication::get() { return AzaleaApplication::s_instance; }
azalea::StandardOutputLogger* azalea::AzaleaApplication::getLogger() { return this->m_logger; }
