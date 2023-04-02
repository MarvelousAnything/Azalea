#ifndef AZALEA_MACROS_HPP
#define AZALEA_MACROS_HPP

#define AZALEA_CONCAT(x, y) x##y

#define AZALEA_MAX(x, y) (x < y) ? y : x
#define AZALEA_MIN(x, y) (x < y) ? x : y

#define AZALEA_ABS(x) x < 0 ? (-x) : x

// Logging Macros
#define AZALEA_LOG_INFO(message, ...) azalea::AzaleaApplication::get()->getLogger()->log(message, ##__VA_ARGS__)
#define AZALEA_LOG_ERROR(type, message, ...) azalea::AzaleaApplication::get()->getLogger()->error(type, message, ##__VA_ARGS__)
#define AZALEA_LOG_GENERIC_ERROR(message, ...) azalea::AzaleaApplication::get()->getLogger()->error(LogErrorType::GENERIC_ERROR, message, ##__VA_ARGS__)

#endif// AZALEA_MACROS_HPP
