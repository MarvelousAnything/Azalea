#include "TestEvent.h"

TestEvent::TestEvent( int x, int y )
{
    this->m_x = x;
    this->m_y = y;
}

void TestEvent::addListener( std::function<void( const TestEvent& )> listeners )
{
    this->m_listeners.push_back( listeners );
}

void TestEvent::invoke()
{
    for ( const auto& item: this->m_listeners ) {
        item( *this );
    }
}