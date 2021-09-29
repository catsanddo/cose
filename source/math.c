#include "math.h"

CATi32 clampi(CATi32 value, CATi32 min, CATi32 max)
{
    return (value * (value < max && value > min)) +
    (min * (value <= min)) +
    (max * (value >= max));
}

CATf32 clampf(CATf32 value, CATf32 min, CATf32 max)
{
    return (value * (value < max && value > min)) +
    (min * (value <= min)) +
    (max * (value >= max));
}

CATf32 lerp(CATf32 a, CATf32 b, CATf32 t)
{
    return a + ((b - a) * t);
}
