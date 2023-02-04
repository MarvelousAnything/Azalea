#ifndef AZALEA_APPLICATION_HPP
#define AZALEA_APPLICATION_HPP

#include <azalea/core/Window.hpp>
#include <stdint.h>
#include <string>

namespace azalea {

    struct ApplicationProps
    {

        uint32_t width;
        uint32_t height;

        std::string name = "Azalea Game";

        bool vsync = true;
        bool resizeable = true;
    };

    class AzaleaApplication {
    public:
        AzaleaApplication( ApplicationProps props );
        ~AzaleaApplication() = default;// TODO (Chloe): Remember to do this

        void run();

        AzaleaWindowManager* getWindowManager();

        static AzaleaApplication* getInstance();

    private:
        std::string m_name;
        bool m_running;

        AzaleaWindowManager* m_windowManager;

        static AzaleaApplication* s_instance;
    };


    AzaleaApplication* createApplication( int argc, const char** argv );

}// namespace azalea

#endif