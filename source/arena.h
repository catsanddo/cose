#ifndef ARENA_H
#define ARENA_H

typedef struct CAT_Arena CAT_Arena;
struct CAT_Arena {
    CATu8 *data;
    CATu64 end;
    CATu64 max;
};

CAT_Arena *CAT_ArenaInit(CATu64 size);
void *CAT_ArenaAlloc(CAT_Arena *arena, CATu64 size);
void CAT_ArenaClear(CAT_Arena *arena);
void CAT_ArenaDestroy(CAT_Arena *arena);

#endif
