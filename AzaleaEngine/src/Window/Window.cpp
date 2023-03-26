#include <Azalea/Window/Window.hpp>
azalea::window::AzaleaWindow::AzaleaWindow( azalea::window::AzaleaWindow* parent,
                                            azalea::window::AzaleaWindowOptions opts )
{
    this->m_parent = parent;
    this->m_children = {};

    if ( this->m_parent != nullptr ) {
        this->m_childID = this->m_parent->m_children.size();
        this->m_parent->m_children.insert( this->m_parent->m_children.end(), this );
    }
    else {
        this->m_childID = -1;
    }

    this->m_width = opts.width;
    this->m_height = opts.height;
    this->m_title = std::move( opts.title );
    this->m_windowMode = opts.windowMode;
    this->m_vsyncEnabled = opts.vsync;
    this->m_shouldClose = false;
}

azalea::window::AzaleaWindow::AzaleaWindow( azalea::window::AzaleaWindowOptions opts ) : AzaleaWindow( nullptr, opts ) {}

azalea::window::AzaleaWindow::~AzaleaWindow()
{
    if ( this->m_parent != nullptr ) {
        this->m_parent->m_children.erase( std::next( this->m_parent->m_children.begin(), this->m_childID ) );
    }
    std::destroy( this->m_children.begin(), this->m_children.end() );
}
azalea::window::AzaleaWindow* azalea::window::AzaleaWindow::createChildWindow( azalea::window::AzaleaWindowOptions opts )
{
    return new AzaleaWindow( this, opts );
}
void azalea::window::AzaleaWindow::show() {}
void azalea::window::AzaleaWindow::hide() {}
void azalea::window::AzaleaWindow::poll() {}

void azalea::window::AzaleaWindow::setWindowMode( azalea::window::AzaleaWindowMode mode ) { this->m_windowMode = mode; }

bool azalea::window::AzaleaWindow::shouldClose() { return this->m_shouldClose; }

azalea::window::AzaleaWindowMode azalea::window::AzaleaWindow::getMode() { return this->m_windowMode; }

void azalea::window::AzaleaWindow::setHeight( int32_t height ) { this->m_height = height; }

int32_t azalea::window::AzaleaWindow::getHeight() { return this->m_height; }

void azalea::window::AzaleaWindow::setWidth( int32_t width ) { this->m_width = width; }

int32_t azalea::window::AzaleaWindow::getWidth() { return this->m_width; }

void azalea::window::AzaleaWindow::setTitle( std::string title ) { this->m_title = title; }
std::string azalea::window::AzaleaWindow::getTitle() { return this->m_title; }
void* azalea::window::AzaleaWindow::getNativeWindowHandle() { return nullptr; }
