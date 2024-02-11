#ifndef MEMORY_H
#define MEMORY_H
#include "./minit_rt.h"

  typedef enum {
    LONG,
    SHORT,
    ALL
  } e_memory_type;
  
  typedef struct {
      t_list *long_memory;
      t_list *short_memory;
      e_memory_type where_write;
      void (*write_in_long)(void);
      void (*write_in_short)(void);
      void (*memory_flush)(e_memory_type where);
  } t_memory;


void *new(size_t count, size_t size_of_struct, void (*ffree)(void *), e_memory_type region);

void memory_flush(e_memory_type where);

void write_in_long(void);

void write_in_short(void);

#endif