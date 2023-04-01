#ifndef AZALEA_WINDOW_HPP
#define AZALEA_WINDOW_HPP

#include <cstdint>
#include <string>

#include <vector>

namespace azalea::window {

    /**
     * @brief The mode the window should be shown in
     */
    enum class AzaleaWindowMode
    {
        FULLSCREEN, /** The window will cover the fullscreen */
        WINDOWED_FULLSCREEN, /** The window will cover the fullscreen but act as if it was just maximized */
        BORDERLESS_WINDOW = WINDOWED_FULLSCREEN, /** The window will cover the fullscreen but act as if it was just maximized */
        WINDOWED /** The window acts as a regular window */
    };

    /**
     * @brief The initial properties of the window
     */
    struct AzaleaWindowOptions
    {
        int32_t width;
        int32_t height;

        std::string title = "Azalea Window";

        AzaleaWindowMode windowMode = AzaleaWindowMode::WINDOWED;
        bool vsync = true;
    };


    /**
     * @brief The main AzaleaWindow platform independent class to manage windows in Azalea
     */
    class AzaleaWindow {
    public:
        AzaleaWindow( AzaleaWindowOptions opts );
        virtual ~AzaleaWindow();


        /**
         * @brief Shows the window to the User
         */
        virtual void show();

        /**
         * @brief Hides the window from the User
         * @note This does not destroy the window it only hides it from view
         */
        virtual void hide();

        /**
         * @brief Polls the window for any events that may or may not have happened
         * @note If this method is not called the window will "Not Respond" and the OS might think the program has crashed
         */
        virtual void poll();

        /**
         * @brief Maximizes the window
         * @note This does not fullscreen it
         */
        virtual void maximizeWindow();

        /**
         * @brief Requests the user's attention to the window
         * @example On the Windows Operating System requesting attention causes the icon on the task bar to flicker
         */
        virtual void requestAttention();

        /**
         * @brief Creates a window that is parented to this window
         * @param opts The options to create the new window with
         * @return teh new Window pointer
         */
        AzaleaWindow* createChildWindow( AzaleaWindowOptions opts );

        /**
         * @brief Checks if the window should be closed. That is, if the window is destroyed or is going to be destroyed
         * @return True, if the window should be closed. False, if the window is to stay opened
         */
        bool shouldClose();

        /**
         * @brief Checks if the window is currently being shown to the user
         * @return True, if the window is being shown. False, if the window is hidden
         */
        bool isWindowShown();

        /**
         * @brief Sets the width of the window
         * @param width The new width of the window
         */
        virtual void setWidth( int32_t width );

        /**
         * @brief Gets the current width of the window
         * @return the current width of the window
         */
        int32_t getWidth();

        /**
         * @brief Sets the height of the window
         * @param height The new height of the window
         */
        virtual void setHeight( int32_t height );

        /**
         * @brief Gets the current height of the window
         * @return the current height of the window
         */
        int32_t getHeight();

        /**
         * @brief Sets the mode of the window
         * @param mode The new mode of the window
         */
        virtual void setWindowMode( AzaleaWindowMode mode );

        /**
         * @brief Gets the current mode of the window
         * @return the current mode of the window
         */
        AzaleaWindowMode getMode();

        /**
         * @brief Sets the title of the window
         * @param title The new title of the window
         */
        virtual void setTitle( std::string title );

        /**
         * @brief Gets the current title of the window
         * @return the current title of the window
         */
        std::string getTitle();

        /**
         * @brief Gets the native window handle as a void pointer
         * @internal This method shouldn't really be used outside of internal code
         * @return The native window handle as a void pointer
         */
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

        bool m_shouldClose;
        bool m_isShowing;

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
