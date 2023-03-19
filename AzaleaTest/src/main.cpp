#include <iostream>
#include <Azalea/Core/Application.hpp>

class TestApplication : public azalea::AzaleaApplication {
    friend class azalea::AzaleaApplication;
public:

    TestApplication() : azalea::AzaleaApplication() {
    }



};

azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv )
{
    return new TestApplication();
}