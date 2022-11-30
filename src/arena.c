#include "arena.h"

CE_Arena *CE_ArenaAlloc(void)
{
    CE_Arena *result = 0;

    void *memory = mmap(0, CE_ARENA_MAX, PROT_NONE,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (memory != (void *) -1) {
        mprotect(memory, CE_ARENA_INITIAL, PROT_READ | PROT_WRITE);
        result = (CE_Arena *) memory;
        result->base = memory + 64;
        result->off = 0;
        result->cap = CE_ARENA_INITIAL;
    }

    return result;
}

void CE_ArenaFree(CE_Arena *arena)
{
    if (!arena || !arena->base) {
        return;
    }
    arena->off = arena->cap = 0;
    munmap(arena->base, CE_ARENA_MAX);
    arena->base = 0;
}

void *CE_ArenaPush(CE_Arena *arena, size_t size)
{
    unsigned char *result = 0;

    size = CE_AlignPow2(size, 8);

    if (arena->off + size <= arena->cap) {
        result = arena->base + arena->off;
        arena->off += size;
    } else if (arena->off + size > CE_ARENA_MAX) {
        return 0;
    } else {
        void *memory = (void *) arena->base - 64;
        arena->cap <<= 1;
        mprotect(memory, arena->cap, PROT_READ | PROT_WRITE);
        return CE_ArenaPush(arena, size);
    }

    return result;
}

void CE_ArenaPop(CE_Arena *arena, size_t size)
{
    size = CE_AlignPow2(size, 8);
    arena->off = CE_Max(arena->off - size, 0);
}
