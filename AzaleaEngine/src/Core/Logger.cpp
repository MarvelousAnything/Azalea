#include <Azalea/Core/Logger.hpp>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>

namespace fs = std::filesystem;

void azalea::StandardOutputLogger::log( std::string message, ... )
{
    std::stringstream ss;

    time_t time = std::time( nullptr );
    auto tm = *std::localtime( &time );

    ss << "[" << std::put_time( &tm, "%I:%M:%S" ) << "] ";
    ss << message;

    va_list vaList;
    va_start( vaList, ss.str().c_str() );
    vprintf( ss.str().c_str(), vaList );
    va_end( vaList );
}

void azalea::StandardOutputLogger::error( azalea::LogErrorType type, std::string message, ... )
{
    std::stringstream ss;

    time_t time = std::time( nullptr );
    auto tm = *std::localtime( &time );

    ss << "[" << std::put_time( &tm, "%I:%M:%S" ) << "] ";

    switch ( type ) {
        case LogErrorType::GENERIC_ERROR:
            ss << "GENERIC ERROR: ";
            break;
    }

    ss << message;

    va_list vaList;
    va_start( vaList, ss.str().c_str() );
    vfprintf( stderr, ss.str().c_str(), vaList );
    va_end( vaList );
}

azalea::FileLogger::FileLogger( const std::string& path, const std::string& fileName )
{
    this->m_path = path;
    if ( path.back() != '/' ) {
        this->m_path += '/';
    }
    this->m_path += fileName;
    this->m_path += ".log";

    if ( !fs::is_directory( path ) || !fs::exists( path ) ) {
        fs::create_directory( path );
    }
}

azalea::FileLogger::FileLogger( const std::string& fileName ) : FileLogger( "logs", fileName )
{
    // TODO(Chloe) When implementing platform specific things make the defaultDir on windows %appdata%/.AzaleaEngine/logs
    //             and on Linux ~/.AzaleaEngine/logs
}

void azalea::FileLogger::log( std::string message, ... )
{
    FILE* f = fopen( this->m_path.c_str(), "w" );

    std::stringstream ss;

    time_t time = std::time( nullptr );
    auto tm = *std::localtime( &time );

    ss << "[" << std::put_time( &tm, "%I:%M:%S" ) << "] ";
    ss << message;

    va_list vaList;
    va_start( vaList, ss.str().c_str() );
    vprintf( ss.str().c_str(), vaList );
    vfprintf( f, ss.str().c_str(), vaList );
    va_end( vaList );
    fclose( f );
}

void azalea::FileLogger::error( azalea::LogErrorType type, std::string message, ... )
{
    FILE* f = fopen( this->m_path.c_str(), "w" );

    std::stringstream ss;

    time_t time = std::time( nullptr );
    auto tm = *std::localtime( &time );

    ss << "[" << std::put_time( &tm, "%I:%M:%S" ) << "] ";
    ss << message;

    va_list vaList;
    va_start( vaList, ss.str().c_str() );
    vfprintf( stderr, ss.str().c_str(), vaList );
    vfprintf( f, ss.str().c_str(), vaList );
    va_end( vaList );
    fclose( f );
}
