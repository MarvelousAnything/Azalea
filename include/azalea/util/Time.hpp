#ifndef AZALEA_TIME_HPP
#define AZALEA_TIME_HPP

#include <cstdint>
#include <chrono>

namespace azalea::util::time {

    class Stopwatch {
    public:
        Stopwatch();
        Stopwatch(const Stopwatch& stopwatch);

        ~Stopwatch() = default;

        void start();
        void end();

        double elapsed();

    private:
        double m_startTime;
        double m_endTime;
    };

}

#endif// AZALEA_TIME_HPP
