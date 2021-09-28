#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// Signed integers
typedef int8_t CATi8;
typedef int16_t CATi16;
typedef int32_t CATi32;
typedef int64_t CATi64;

// Unsigned integers
typedef uint8_t CATu8;
typedef uint16_t CATu16;
typedef uint32_t CATu32;
typedef uint64_t CATu64;

// Floating point numbers
typedef float CATf32;
typedef double CATf64;

// Make static unambiguous
#define global static
#define internal static

#endif
