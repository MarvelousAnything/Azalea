#include <azalea/event/Event.hpp>

void azalea::event::Event::registerListener( azalea::event::EventListener listener )
{
    this->m_listeners.push_back( listener );
}

void azalea::event::Event::invoke()
{
    for ( auto& listener: this->m_listeners ) {
        listener( *this );
    }
}
