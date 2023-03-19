#ifndef AZALEA_LOGGER_HPP
#define AZALEA_LOGGER_HPP

#include <cstdarg>
#include <ostream>
#include <string>

namespace azalea {

    /**
     * @brief An enum consisting of various error types that can be used for logging specific errors
     */
    enum class LogErrorType
    {
        GENERIC_ERROR = 0, /**An error that is not part of any major set of issues but still might be useful to log */
    };

    class Logger {
    public:
        Logger() = default;
        ~Logger() = default;
        /**
         * @brief Creates a standard log message
         * @param message A string containing the message you want to log along with appropriate formatting
         * @param ... A va_list of args to apply to the log message
         * @note The function uses the same formatting that can be found in printf()
         */
        virtual void log( std::string message, ... ) = 0;
        /**
         * @brief Creates an error log message
         * @param message A string containing the message you want to log along with appropriate formatting
         * @param ... A va_list of args to apply to the log message
         * @note The function uses the same formatting that can be found in printf()
         * @note The function automatically appends the error name to the message
         */
        virtual void error( LogErrorType type, std::string message, ... ) = 0;
    };

    /**
     * @brief Sends log messages to the Standard Output similarly to std::cout
     */
    class StandardOutputLogger : public Logger {
        friend class Logger;

    public:
        StandardOutputLogger() = default;
        ~StandardOutputLogger() = default;

        void log( std::string message, ... ) override;
        void error( LogErrorType type, std::string message, ... ) override;
    };

    /**
     * @brief Sends log messages to both the standard output and the file specified
     * @note If the file you provided already exists, the new logs will replace the old contents of the file
     */
    class FileLogger : public Logger {
        friend class Logger;

    public:
        /**
         * @brief Creates a log file with the specified file name in the specified directory.
         * @param dir A constant reference to a string containing the directory path to create the log file in.
         * @param fileName A constant reference to a string containing the name of the log file.
         * @note The constructor assumes that the directory path provided is valid
         * @note The constructor assumes that the fileName does not end in .log
         */
        FileLogger( const std::string& dir, const std::string& fileName );
        /**
         * Creates a log file with the specified file name in the default Azalea Log directory.
         * @param fileName A constant reference to a string containing the name of the log file.
         * @note The constructor assumes that the fileName does not end in .log
         */
        FileLogger( const std::string& fileName );
        ~FileLogger() = default;

        void log( std::string message, ... ) override;
        void error( LogErrorType type, std::string message, ... ) override;

    private:
        std::string m_path;
    };

}// namespace azalea

#endif// AZALEA_LOGGER_HPP
