#include <azalea/util/GladUtil.hpp>
#include <cstdlib>

GladGLContext* azalea::util::createGLADContext( GLFWwindow* window )
{
    glfwMakeContextCurrent( window );

    GladGLContext* context = ( GladGLContext* ) calloc( 1, sizeof( GladGLContext ) );
    if ( context == nullptr ) return nullptr;

    gladLoadGLContext( context, glfwGetProcAddress );

    return context;
}

void azalea::util::destroyGLADContext( GladGLContext* context ) { free( context ); }