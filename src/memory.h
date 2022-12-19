#ifndef MEMORY_H
#define MEMORY_H

void *CE_MemReserve(size_t length);
int CE_MemRelease(void *addr, size_t length);
int CE_MemCommit(void *addr, size_t length);
int CE_MemDecommit(void *addr, size_t length);

#endif
