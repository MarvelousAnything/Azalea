#ifndef AZALEA_TESTAPPLICATION_HPP
#define AZALEA_TESTAPPLICATION_HPP

#include <azalea/core/Application.hpp>
#include <azalea/core/Entry.hpp>

namespace test {

    class TestApplication : public azalea::AzaleaApplication {
        friend class azalea::AzaleaApplication;

    public:
        TestApplication(azalea::ApplicationProps& props);
        ~TestApplication();

    };

}
#endif// AZALEA_TESTAPPLICATION_HPP
