#include "../../includes/memory.h"

t_memory g_memory;

void memory_flush(unsigned char coliseu_id)
{
    ft_arena_free(&g_memory.memory[coliseu_id]);
}

void* new(size_t count, size_t size_of_struct, unsigned char coliseu_id)
{
    return ft_arena_alloc(count * size_of_struct, &g_memory.memory[coliseu_id]);
}

void memory_destroy(void) {
    ft_arena_destroy(&g_memory.memory[SHORT]);
    ft_arena_destroy(&g_memory.memory[LONG]);
}
