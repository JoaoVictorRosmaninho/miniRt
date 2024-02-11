#include "../../includes/minit_rt.h"

t_list *memory = NULL;


static void initialize(void) {
    memory = ft_lstnew();
}

void memory_flush(void) {
    ft_printf("[+] - Memory: %d items cleaned [+]", memory->size);
    ft_lstclear(memory, vector_free);
    free(memory);
}

void *new(size_t count, size_t size_of_struct, void (*ffree)(void *)) {

    if (!memory) initialize();

    void* s = ft_calloc(count, size_of_struct);

    ft_lstadd_front(memory, ft_lstnew_node(mk_generic_content((void *) s)));
    
    if (memory->size >= MSIZE)
        ft_lstdelone(ft_lstpop_head(memory), ffree);

    return (s); 
}