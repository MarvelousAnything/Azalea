#include <Azalea/Core/Event.hpp>

azalea::TestEvent::TestEvent( int x, int y )
{
    this->m_x = x;
    this->m_y = y;
}

void azalea::TestEvent::addListener( std::function<void( const TestEvent& )> listeners )
{
    this->m_listeners.push_back( listeners );
}

void azalea::TestEvent::invoke()
{
    for ( const auto& item: this->m_listeners ) {
        item( *this );
    }
}
