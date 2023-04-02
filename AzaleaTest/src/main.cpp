#include <Azalea/Core/Application.hpp>
#include <Azalea/Platform/Unix/UnixEntry.hpp>
#include "Azalea/Platform/Unix/UnixWindow.hpp"
#include "TestEvent.h"

class TestApplication : public azalea::AzaleaApplication {
    friend class azalea::AzaleaApplication;

public:
    TestApplication() : azalea::AzaleaApplication() {}

    void run() override {
        azalea::window::AzaleaWindowOptions opts = { .width = 720,
                                                     .height = 720,
                                                     .title = "Test",
                                                     .windowMode = azalea::window::AzaleaWindowMode::WINDOWED }; // no clue if fullscreen works...

        auto* winWin = new azalea::window::UnixWindow(opts);
        azalea::window::AzaleaWindow* win = (azalea::window::AzaleaWindow*) winWin;

        win->show();
        while (!win->shouldClose()) {
            win->setWidth(920);
            win->poll();
        }
    };
};

azalea::AzaleaApplication* azalea::instantiateGame( uint32_t argc, char** argv ) { return new TestApplication(); }