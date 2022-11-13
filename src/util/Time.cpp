#include <azalea/util/Time.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

azalea::util::time::Stopwatch::Stopwatch()
{
    this->m_startTime = 0;
    this->m_endTime = -1;
}

azalea::util::time::Stopwatch::Stopwatch( const azalea::util::time::Stopwatch& stopwatch )
{
    this->m_startTime = stopwatch.m_startTime;
    this->m_endTime = stopwatch.m_endTime;
}

void azalea::util::time::Stopwatch::start()
{
    this->m_startTime = glfwGetTime();
}

void azalea::util::time::Stopwatch::end()
{
    this->m_endTime = glfwGetTime();
}

double azalea::util::time::Stopwatch::elapsed() {
    if (this->m_endTime == 0) {
        return glfwGetTime() - this->m_startTime;
    }
    return this->m_endTime - glfwGetTime();
}
