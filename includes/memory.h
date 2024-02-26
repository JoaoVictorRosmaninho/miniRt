#ifndef MEMORY_H
# define MEMORY_H
# include "./minit_rt.h"

# define SHORT 0
# define LONG  1
# define COLISEU_SIZES 2

typedef struct {
  t_coliseu memory[COLISEU_SIZES];
  unsigned char coliseu_id;
} t_memory;

void* new(size_t count, size_t size_of_struct, unsigned char coliseu_id);

void memory_flush(unsigned char coliseu_id);

void memory_destroy(void);
#endif