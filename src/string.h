#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include "arena.h"

#define CE_StrVArg(s) s.length, s.str
#define CE_StrLit(s) (CE_String) { (s), sizeof(s)-1 }

typedef struct CE_String CE_String;
struct CE_String {
    char *str;
    size_t length;
};

CE_String CE_StrC(CE_Arena *arena, const char *str);

#endif
