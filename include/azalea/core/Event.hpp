#ifndef AZALEA_EVENT_HPP
#define AZALEA_EVENT_HPP

#include <vector>

namespace azalea {
    class Event;
    typedef void EventListener( const Event& event );

    class Event {
    public:
        Event();
        ~Event();

        void addListener( EventListener listener );
        void invoke();

    protected:
        std::vector<EventListener*> m_listeners;
    };

}// namespace azalea

#endif// AZALEA_EVENT_HPP
