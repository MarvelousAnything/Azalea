#ifndef AZALEA_APPLICATION_HPP
#define AZALEA_APPLICATION_HPP

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
        AzaleaApplication( ApplicationProps& props );
        ~AzaleaApplication();

        void run();

    private:

        std::string m_name;
    };


    AzaleaApplication* createApplication( int argc, const char** argv );

}// namespace azalea

#endif