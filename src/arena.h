#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stddef.h>

#define CE_ARENA_MAX (32l << 20)
#define CE_ARENA_INITIAL ( 4l << 10)

#define CE_ArenaClear(a) ArenaPop(a, (a)->off)

typedef struct CE_Arena CE_Arena;
struct CE_Arena {
    uint8_t *base;
    size_t off;
    size_t cap;
};

CE_Arena *CE_ArenaAlloc(void);
void CE_ArenaFree(CE_Arena *CE_arena);
void *CE_ArenaPush(CE_Arena *CE_arena, size_t size);
void CE_ArenaPop(CE_Arena *CE_arena, size_t size);

#endif
