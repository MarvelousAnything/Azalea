#include <azalea/core/Event.hpp>

azalea::Event::Event() { this->m_listeners = {}; }

azalea::Event::~Event() {}

void azalea::Event::addListener( azalea::EventListener listener )
{
    this->m_listeners.insert( this->m_listeners.end(), listener );
}

void azalea::Event::invoke()
{
    for ( const auto& listener: this->m_listeners ) {
        listener( *this );
    }
}
