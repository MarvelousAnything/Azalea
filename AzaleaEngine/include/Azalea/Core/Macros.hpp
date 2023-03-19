#ifndef AZALEA_MACROS_HPP
#define AZALEA_MACROS_HPP

#define AZALEA_CONCAT(x, y) x##y

#define AZALEA_MAX(x, y) (x < y) ? y : x
#define AZALEA_MIN(x, y) (x < y) ? x : y

#define AZALEA_ABS(x) x < 0 ? -x : x;

#endif// AZALEA_MACROS_HPP
