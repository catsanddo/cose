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

int CE_StrCmp(CE_String a, CE_String b)
{
    if (a.length != b.length) {
        return a.length - b.length;
    }
    for (size_t i = 0; i < a.length; ++i) {
        if (a.str[i] != b.str[i]) {
            return a.str[i] - b.str[i];
        }
    }

    return 0;
}
