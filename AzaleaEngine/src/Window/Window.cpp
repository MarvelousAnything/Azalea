#include <Azalea/Window/Window.hpp>
azalea::window::AzaleaWindow::AzaleaWindow( azalea::window::AzaleaWindow* parent,
                                            azalea::window::AzaleaWindowOptions opts )
{
    this->m_parent = parent;
    this->m_children = {};

    if (this->m_parent != nullptr) {
        this->m_childID = this->m_parent->m_children.size();
        this->m_parent->m_children.insert(this->m_parent->m_children.end(), this);
    } else {
        this->m_childID = -1;
    }

    this->m_width = opts.width;
    this->m_height = opts.height;
    this->m_title = std::move(opts.title);
    this->m_windowMode = opts.windowMode;
    this->m_vsyncEnabled = opts.vsync;
}

azalea::window::AzaleaWindow::AzaleaWindow( azalea::window::AzaleaWindowOptions opts ) : AzaleaWindow(nullptr, opts)
{

}

azalea::window::AzaleaWindow::~AzaleaWindow()
{
    if (this->m_parent != nullptr) {
        this->m_parent->m_children.erase(std::next(this->m_parent->m_children.begin(), this->m_childID));
    }
    std::destroy( this->m_children.begin(), this->m_children.end() );
}
azalea::window::AzaleaWindow* azalea::window::AzaleaWindow::createChildWindow( azalea::window::AzaleaWindowOptions opts )
{
    return new AzaleaWindow(this, opts);
}
void azalea::window::AzaleaWindow::show() {}
void azalea::window::AzaleaWindow::hide() {}
