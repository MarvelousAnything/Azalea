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

        AzaleaWindowMode windowMode = AzaleaWindowMode::WINDOWED;
        bool vsync = true;
    };

    // Putting this here because it is for the window and I currently don't have good access to Trello... oops!
    // TODO(Chloe): Setting window icon
    // TODO(Chloe): Setting window cursor
    // TODO(Chloe): Minimizing window
    class AzaleaWindow {
    public:
        AzaleaWindow( AzaleaWindowOptions opts );
        virtual ~AzaleaWindow();


        virtual void show();
        virtual void hide();
        virtual void poll();

        AzaleaWindow* createChildWindow( AzaleaWindowOptions opts );

        virtual void setWidth( int32_t width );
        int32_t getWidth();

        virtual void setHeight( int32_t height );
        int32_t getHeight();

        virtual void setWindowMode( AzaleaWindowMode mode );
        AzaleaWindowMode getMode();

        virtual void setTitle( std::string title );
        std::string getTitle();

        virtual void* getNativeWindowHandle();

        /*
         * These methods require a graphics library loaded.
         * The functionality these methods give will be implemented when a graphics library -- either OpenGL or Vulcan --
         * get implemented.
         *
         * For more info visit: https://www.khronos.org/opengl/wiki/Swap_Interval
         *
         * virtual void setVSync(bool vsync);
         * bool isVSyncEnabled();
         *
         * virtual void swapBuffers();
         */
    protected:
        AzaleaWindow( AzaleaWindow* parent, AzaleaWindowOptions opts );

        AzaleaWindow* m_parent;
        int32_t m_childID;
        std::vector<AzaleaWindow*> m_children;

    private:
        int32_t m_width;
        int32_t m_height;

        AzaleaWindowMode m_windowMode;
        bool m_vsyncEnabled;// TODO(Chloe) Get VSync working (This is not possible right now see comment on starting on
                            // line 58)

        std::string m_title;
    };

}// namespace azalea::window

#endif// AZALEA_WINDOW_HPP
