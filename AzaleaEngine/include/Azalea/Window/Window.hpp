#ifndef AZALEA_WINDOW_HPP
#define AZALEA_WINDOW_HPP

#include <cstdint>
#include <string>

#include <vector>

namespace azalea::window {

    enum class AzaleaWindowMode
    {
        FULLSCREEN,
        WINDOWED_FULLSCREEN,
        BORDERLESS_WINDOW = WINDOWED_FULLSCREEN,
        WINDOWED
    };

    struct AzaleaWindowOptions
    {
        int32_t width;
        int32_t height;

        std::string title = "Azalea Window";

        AzaleaWindowMode windowMode = AzaleaWindowMode::WINDOW;
        bool vsync = true;
    };

    class AzaleaWindow {
    public:
        AzaleaWindow( AzaleaWindowOptions opts );
        ~AzaleaWindow();


        virtual void show();
        virtual void hide();

        AzaleaWindow* createChildWindow( AzaleaWindowOptions opts );

    protected:
        AzaleaWindow( AzaleaWindow* parent, AzaleaWindowOptions opts );

        AzaleaWindow* m_parent;
        int32_t m_childID;
        std::vector<AzaleaWindow*> m_children;

    private:
        int32_t m_width;// TODO(Chloe) change width and height of window
        int32_t m_height;

        AzaleaWindowMode m_windowMode;// TODO(Chloe) Get window mode working
        bool m_vsyncEnabled;          // TODO(Chloe) Get VSync working

        std::string m_title;// TODO(Chloe) Change Window Title
    };

}// namespace azalea::window

#endif// AZALEA_WINDOW_HPP
