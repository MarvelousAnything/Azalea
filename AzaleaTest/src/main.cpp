#include <Azalea/Core/Application.hpp>
#include <Azalea/Platform/Platform.hpp>
#include <Azalea/Platform/Windows/WindowsEntry.hpp>
#include <iostream>

class TestApplication : public azalea::AzaleaApplication {
    friend class azalea::AzaleaApplication;

public:
    TestApplication() : azalea::AzaleaApplication() {}

    void run() override {
        azalea::window::AzaleaWindowOptions opts = { .width = 720,
                                                     .height = 720,
                                                     .title = "Test",
                                                     .windowMode = azalea::window::AzaleaWindowMode::WINDOWED }; // no clue if fullscreen works...

        auto* win = new azalea::window::WindowsWindow(opts);
        win->show();
        while (!win->shouldClose()) {


            win->poll();
        }
    };
};

azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv ) { return new TestApplication(); }