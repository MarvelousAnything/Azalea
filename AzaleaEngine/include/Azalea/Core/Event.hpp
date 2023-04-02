#ifndef AZALEA_EVENT_HPP
#define AZALEA_EVENT_HPP

#include <vector>
#include <functional>

namespace azalea {

    /**
     * @brief The base event interface for the Event System. Due to spaghetti code addListener is a virtual method... Sorry not sorry
     * @tparam T The class of the event implementing this interface
     */
    template <typename T>
    class Event {
    public:
        Event() = default;
        ~Event() = default;

        /**
         * @brief Adds a listener to be run when the event gets invoked
         * @param listener An std::function with a const reference to the current event class
         */
        virtual void addListener(std::function<void(const T&)> listener) = 0;
        virtual void invoke() = 0;
    protected:
        std::vector<std::function<void(const T&)>> m_listeners; // TODO(Chloe) I might make this a full interface and just remove this
    };

}

#endif// AZALEA_EVENT_HPP
