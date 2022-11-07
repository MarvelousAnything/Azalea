#include <TestApplication.hpp>

test::TestApplication::TestApplication( azalea::ApplicationProps& props )
    : azalea::AzaleaApplication(props)
{

}

test::TestApplication::~TestApplication()
{

}

azalea::AzaleaApplication* azalea::instantiateAzaleaApplication( int32_t argc, const char** argv )
{
    ApplicationProps props = {.width = 720, .height = 720};

    return new test::TestApplication(props);
}