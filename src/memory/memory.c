#include "../../includes/memory.h"

t_memory* memory = NULL;

static void initialize(void) {
    memory                 = ft_calloc(1, sizeof(t_memory));
    memory->long_memory    = ft_lstnew();
    memory->short_memory   = ft_lstnew();
    memory->where_write    = LONG;
    memory->write_in_long  = write_in_long;
    memory->write_in_short = write_in_short;
    memory->memory_flush   = memory_flush;
}

void memory_flush(e_memory_type where) {
    
    if (where == LONG) {
        ft_lstclear(memory->long_memory);
    } else if (where == SHORT) {
        ft_lstclear(memory->short_memory);
    } else if (ALL) {
        ft_printf("[+] - Long Memory: %d items cleaned [+]\n", memory->long_memory->size);
        ft_printf("[+] - SHORT Memory: %d items cleaned [+]\n", memory->short_memory->size);
        ft_lstclear(memory->long_memory);
        ft_lstclear(memory->short_memory);
        free(memory->long_memory);
        free(memory->short_memory);
        free(memory);
    }
}

void* new(size_t count, size_t size_of_struct, void (*ffree)(void *), e_memory_type region) {

    if (!memory) initialize();


    void* s = ft_calloc(count, size_of_struct);

    if (region == LONG) {
        ft_lstadd_back(memory->long_memory, ft_lstnew_node(s, POINTER, ffree));
        if (memory->long_memory->size > LSIZE) 
            ft_lstdelone(ft_lstpop_head(memory->long_memory));

    } else if (region == SHORT) {
        ft_lstadd_back(memory->short_memory, ft_lstnew_node(s, POINTER, ffree));
    }

    return (s); 
}


void write_in_long(void) {
    if (!memory) initialize();
    memory->where_write = LONG;
}

void write_in_short(void) {
    if (!memory) initialize();
    memory->where_write = SHORT;
}