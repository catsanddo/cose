#include <stdlib.h>

CAT_Arena *CAT_ArenaInit(CATu64 size)
{
    CAT_Arena *arena = malloc(sizeof(CAT_Arena));

    arena->data = malloc(size);
    arena->end = 0;
    arena->max = size;

    return arena;
}

void *CAT_ArenaAlloc(CAT_Arena *arena, CATu64 size)
{
    // Align memory to sizeof(void *)
    CATu64 alginment = sizeof(void *);
    CATu64 result_offset = arena->end;
    result_offset += alignment - 1;
    result_offset -= result_offset % alignment;

    // Get memory address and move arena offset if enough space
    void *result = 0;
    if (result_offset + size <= arena->max) {
        result = arena->data + result_offset;
        arena->end = result_offset + size;
    }

    return result;
}

void CAT_ArenaClear(CAT_Arena *arena)
{
    arena->end = 0;
}

void CAT_ArenaDestroy(CAT_Arena *arena)
{
    free(arena->data);
    free(arena);
}
