#ifndef AZALEA_PROFILER_HPP
#define AZALEA_PROFILER_HPP

#include <cstdint>
#include <string>
#include <map>

namespace azalea::debug {

    struct ProfileSession {
        const std::string& name;

        uint64_t startTime;
        uint64_t endTime;

        std::string file;
    };

    class Profiler {
    public:
        Profiler();
        ~Profiler();

        void startProfile(const std::string& session, std::string file = "profiler.ini");
        void stopProfile(const std::string& session);

        static Profiler* getInstance();

    private:
        void printSession(ProfileSession& session);

        std::map<std::string, ProfileSession> m_activeSessions;
        static Profiler* s_instance;

    };

}

#ifdef AZALEA_DEBUG_ENABLE

#define AZALEA_START_PROFILE(session) azalea::debug::Profiler::getInstance()->startProfile(session)
#define AZALEA_STOP_PROFILE(session) azalea::debug::Profiler::getInstance()->stopProfile(session)

#define AZALEA_START_PROFILE_FUNCTION() AZALEA_START_PROFILE(__func__)
#define AZALEA_STOP_PROFILE_FUNCTION() AZALEA_STOP_PROFILE(__func__)
#else

#define AZALEA_START_PROFILE(session)
#define AZALEA_STOP_PROFILE(session)

#define AZALEA_START_PROFILE_FUNCTION()
#define AZALEA_STOP_PROFILE_FUNCTION()

#endif

#endif// AZALEA_PROFILER_HPP
