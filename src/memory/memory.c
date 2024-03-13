#include "../../includes/memory.h"

t_memory g_memory;

void memory_flush(unsigned char coliseu)
{
    ft_arena_free(&g_memory.memory[coliseu]);
}

void* new(size_t count, size_t size_of_struct, t_coliseu* coliseu)
{
    return ft_calloc(count, size_of_struct, coliseu);
}

void memory_destroy(t_coliseu* coliseu) {
    if (coliseu) {
        ft_arena_destroy(coliseu);
        return;     
    }
    ft_coliseu_manager(GIVE_BACK);
}
