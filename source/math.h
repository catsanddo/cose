#ifndef MATH_H
#define MATH_H

// A pair of clamping functions
CATi32 clampi(CATi32 value, CATi32 min, CATi32 max);
CATf32 clampf(CATf32 value, CATf32 min, CATf32 max);

// Linear interpolation
CATf32 lerp(CATf32 a, CATf32 b, CATf32 t);

#endif
