#ifndef MEMORY_H
# define MEMORY_H
# include "./minit_rt.h"

# define SHORT 0
# define LONG  1
# define COLISEU_SIZES 2


void* new(size_t count, size_t size_of_struct, t_coliseu* coliseu);

void memory_flush(t_coliseu* coliseu);

void memory_destroy(t_coliseu* coliseu);
#endif