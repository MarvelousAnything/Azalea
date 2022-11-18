#include <azalea/debug/Profiler.hpp>
#include <fstream>
#include <spdlog/spdlog.h>
#include <sstream>

azalea::debug::Profiler* azalea::debug::Profiler::s_instance = nullptr;

azalea::debug::Profiler::Profiler()
{
    this->m_activeSessions = {};
    Profiler::s_instance = this;
}

azalea::debug::Profiler::~Profiler()
{
    for ( auto& session: this->m_activeSessions ) {
        this->stopProfile( session.first );
    }
    this->m_activeSessions.clear();
    Profiler::s_instance = nullptr;
}

void azalea::debug::Profiler::startProfile( const std::string& session, std::string file )
{
    ProfileSession newSession = { .startTime = 0,
                                  .name = session,
                                  .file = std::move( file ) };// TODO(Chloe) When time gets added fix this
    this->m_activeSessions.insert( { session, newSession } );
}

void azalea::debug::Profiler::stopProfile( const std::string& session )
{
    ProfileSession currentSession = this->m_activeSessions[session];
    currentSession.endTime = 0;// TODO(Chloe) When time gets added fix this

    this->printSession( currentSession );
}

azalea::debug::Profiler* azalea::debug::Profiler::getInstance()
{
    if ( Profiler::s_instance == nullptr ) {
        return new Profiler();// should not be null
    }
    return Profiler::s_instance;
}

void azalea::debug::Profiler::printSession( azalea::debug::ProfileSession& session )
{

    std::stringstream ss{};
    ss << "[" << session.name << "]\nstartTime=" << session.startTime << "\nendTime=" << session.endTime
       << "\nelapsedTime=" << session.endTime - session.startTime << "\n\n";

    SPDLOG_DEBUG( ss.str() );

    std::ofstream filebuf;

    filebuf.open( session.name, std::fstream::app );
    filebuf << ss.str();
    filebuf.close();
}
