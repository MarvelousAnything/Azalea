#ifndef AZALEA_APPLICATION_HPP
#define AZALEA_APPLICATION_HPP

#include <Azalea/Core/Logger.hpp>
#include <Azalea/Window/Window.hpp>

namespace azalea {

    struct PlatformInfo
    {
        std::string platformName;
    };

    /**
     * @brief The application framework for Azalea
     * @note This class is a singleton
     */
    class AzaleaApplication {
    public:
        /**
         * @brief Creates the application and sets up some values that are crucial to runtime
         * @param applicationName the name of the application as an std::string
         * @note The applicationName will be the title of the main window
         * @note By default the applicationName is "Made With Azalea"
         */
        AzaleaApplication( std::string applicationName = "Made With Azalea" );
        ~AzaleaApplication();

        /**
         * @brief Runs all of the game's core logic such as the render loop and handling physics
         * @internal The end-user should NOT UNDER NO CIRCUMSTANCES call this method it is for internal use only
         */
        virtual void run();

        /**
         * @brief Gets the application framework singleton
         * @return the AzaleaApplication singleton
         */
        static AzaleaApplication* get();

        void setPlatformInfo(PlatformInfo* info);

        /**
         * @brief Gets the main logger
         * @return the main logger
         */
        StandardOutputLogger* getLogger();

        PlatformInfo* getPlatformInfo();

    private:
        static AzaleaApplication* s_instance;

        std::string m_name;

        StandardOutputLogger* m_logger; // TODO(Chloe): Change this to FileLogger when the logging path gets fixed

        PlatformInfo* m_platform;
    };

    /**
     * @brief User defined way to create the application. This function exposes both argc and argv allowing more control over the state of the application
     * @param argc same functionality as int main()
     * @param argv same functionality as int main()
     * @return An AzaleaApplication pointer containing all the pre-configuration requirements
     */
    AzaleaApplication* instantiateGame( uint32_t argc, char** argv );

}

#endif// AZALEA_APPLICATION_HPP
