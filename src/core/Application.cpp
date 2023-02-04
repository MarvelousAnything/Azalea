#include <azalea/core/Application.hpp>
#include <azalea/core/Entry.hpp>


azalea::AzaleaApplication* azalea::AzaleaApplication::s_instance = nullptr;

azalea::AzaleaApplication::AzaleaApplication( ApplicationProps props )
{
    this->m_name = std::move( props.name );
    this->m_running = false;


    this->m_windowManager = new AzaleaWindowManager();

    AzaleaWindowProps windowProps = { .width = props.width,
                                      .height = props.height,
                                      .resize = props.resizeable,
                                      .title = props.name };
    this->m_windowManager->createWindow( "main", windowProps );

    AzaleaApplication::s_instance = this;
}

void azalea::AzaleaApplication::run()
{
    this->m_running = true;

    AzaleaWindow* mainWin = this->m_windowManager->getWindow( "main" );
    mainWin->show();
    while ( this->m_running && !mainWin->shouldClose() ) {


        glfwPollEvents();
    }
}

azalea::AzaleaWindowManager* azalea::AzaleaApplication::getWindowManager() { return this->m_windowManager; }

azalea::AzaleaApplication* azalea::AzaleaApplication::getInstance() { return AzaleaApplication::s_instance; }
