#ifndef MINIRT_H
#define MINIRT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#include "../libs/libft/includes/libft.h"


# define WIDTH 400
# define ASPECT 16/9.0
# define VIEWPORT 2.0
# define MSIZE 40

typedef struct s_vector {
    float x;
    float y;
    float z;
} t_vector;

typedef t_vector t_color;


typedef struct s_ray {
    t_vector  *origin;
    t_vector  *direction;
} t_ray ;


typedef struct {
    int height;
    int width;
    int file;
} t_context;



typedef enum {
    CMD_ERROR,
    MEM_ERROR,
    NO_ERROR
} e_errors;

// Global

// utils

void    vector_write_color(t_vector *v, int out);
void    vector_to_str(t_vector *v);


// memory

void *new(size_t count, size_t size_of_struct, void (*ffree)(void *));
void memory_flush(void);


// vector operations

t_vector* vsum(t_vector *a, t_vector *b);
t_vector* vsub(t_vector *a, t_vector *b);
t_vector* vmult(t_vector *a, t_vector *b);
t_vector* vmultf(t_vector *a, float factor);
t_vector* vdivf(t_vector *a, float factor);
t_vector* vector_new(float x, float y, float z);
void      vector_free(void *vector);
double    vsqrt(t_vector *a);
float     vsquared(t_vector *a);

#endif