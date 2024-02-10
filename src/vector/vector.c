#include "../../includes/minit_rt.h"

void    vector_write_color(t_vector *v, int out)
{ 
    ft_fprintf(out, "%d %d %d\n", (int)v->x, (int)v->y, (int)v->z);
}

void vector_to_str(t_vector *v) {
    printf("X: %f, Y: %f, Z: %f\n", v->x, v->y, v->z);
}


t_vector* vsum(t_vector *a, t_vector *b) {
    return (vector_new(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vector* vsub(t_vector *a, t_vector *b) {
    return (vector_new(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vector* vmult(t_vector *a, t_vector *b) {
    return (vector_new( a->x * b->x, a->y * b->y, a->z * b->z));
}


t_vector* vmultf(t_vector *a, float factor) {
    return (vector_new(a->x * factor, a->y * factor, a->z * factor));
}


t_vector* vdivf(t_vector *a, float factor) {
    return (vmultf(a, 1 / factor));
}

t_vector* vector_new(float x, float y, float z) {

    t_vector* vector = ft_calloc(1, sizeof(t_vector));

    vector->x = x;
    vector->y = y;
    vector->z = z;

    if (memory->size >= MSIZE) {
        ft_lstdelone(ft_lstpop_head(memory), vector_free);
    } else {
        ft_lstadd_front(memory, mk_generic_content((void *) vector));
    }

    return (vector);
}

void    vector_free(void *vector) {
    free((t_vector *) vector);
}
