#include <azalea/core/Application.hpp>

azalea::AzaleaApplication::AzaleaApplication( ApplicationProps& props )
{
    this->m_name = std::move(props.name);
}

void azalea::AzaleaApplication::run()
{

}
