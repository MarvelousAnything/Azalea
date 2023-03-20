#include <Azalea/Core/Application.hpp>
#include <Azalea/Platform/Windows/WindowsWindow.hpp>
#include <iostream>

class TestApplication : public azalea::AzaleaApplication {
    friend class azalea::AzaleaApplication;

public:
    TestApplication() : azalea::AzaleaApplication()
    {
        azalea::window::AzaleaWindowOptions opts = { .width = 720,
                                                     .height = 720,
                                                     .windowMode = azalea::window::AzaleaWindowMode::FULLSCREEN };
        auto* win = new azalea::window::WindowsWindow( opts );
        win->show();
        while ( 1 )
            ;
    }
};

azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv ) { return new TestApplication(); }