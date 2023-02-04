#ifndef AZALEA_EVENT_HPP
#define AZALEA_EVENT_HPP

#include <vector>

namespace azalea::event {

    class Event;

    typedef void ( *EventListener )( Event& );

    class Event {
    public:
        Event() = default;
        Event( const Event& event ) = default;

        ~Event() = default;

        void registerListener( EventListener listener );

        void invoke();

    private:
        std::vector<EventListener> m_listeners;
    };

}// namespace azalea::event

#endif// AZALEA_EVENT_HPP
