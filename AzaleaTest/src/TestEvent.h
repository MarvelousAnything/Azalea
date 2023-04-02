#ifndef AZALEA_TESTEVENT_H
#define AZALEA_TESTEVENT_H

#include <Azalea/Core/Event.hpp>


class TestEvent : public azalea::Event<TestEvent> {
    friend class Event<TestEvent>;
public:
    TestEvent(int x, int y);
    virtual ~TestEvent() = default;

    [[nodiscard]] int getX() const { return this->m_x; };
    [[nodiscard]] int getY() const { return this->m_y; };

    void addListener( std::function<void( const TestEvent& )> listeners ) override;

    void invoke() override;
private:
    int m_x;
    int m_y;
};


#endif //AZALEA_TESTEVENT_H
