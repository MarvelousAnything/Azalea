#include <azalea/core/Application.hpp>
#include <iostream>

class TestApplication : public azalea::AzaleaApplication {
    friend class azalea::AzaleaApplication;
public:
    TestApplication() : AzaleaApplication({.width = 720, .height = 720}) {
        std::cout << "Hello, World!\n";
    }
};

azalea::AzaleaApplication* azalea::createApplication( int argc, const char** argv )
{
    return new TestApplication();
}