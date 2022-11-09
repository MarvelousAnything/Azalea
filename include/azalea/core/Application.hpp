#ifndef AZALEA_APPLICATION_HPP
#define AZALEA_APPLICATION_HPP

#include <cstdint>
#include <string>

namespace azalea {

    struct ApplicationProps {

        uint32_t width;
        uint32_t height;

        std::string name = "Made with Azalea";

        bool vsync = true;

    };

    class AzaleaApplication {
    public:
        AzaleaApplication(ApplicationProps& applicationProps);
        ~AzaleaApplication();

        void run(); // backend run function to make things work

        static AzaleaApplication* getInstance();
    private:

        ApplicationProps& m_applicationProps;

        static AzaleaApplication* s_instance;
    };

    AzaleaApplication* instantiateAzaleaApplication(int32_t argc, const char** argv);

}

#endif// AZALEA_APPLICATION_HPP
