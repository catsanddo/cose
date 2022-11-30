#include "string.h"

CE_String CE_StrC(CE_Arena *arena, const char *str)
{
    size_t length = 0;
    CE_String result;

    while (str[length++] != 0);

    result.length = length - 1;
    result.str = CE_ArenaPush(arena, length);
    for (size_t i = 0; i < length; ++i) {
        result.str[i] = str[i];
    }

    return result;
}
