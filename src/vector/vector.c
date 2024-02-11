#include "../../includes/minit_rt.h"

extern t_memory* memory;

void    vector_write_color(t_vector *v, int out)
{ 
    ft_fprintf(out, "%d %d %d\n", (int)(v->x * 255), (int)(v->y * 255), (int)(v->z * 255));
}

void vector_to_str(t_vector *v) {
    printf("X: %f, Y: %f, Z: %f\n", v->x, v->y, v->z);
}

t_vector* vsum(t_vector *a, t_vector *b) {
    if (memory->where_write == SHORT)
        return (_vector_new(a->x + b->x, a->y + b->y, a->z + b->z));
    return (vector_new(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vector* vsub(t_vector *a, t_vector *b) {
    if (memory->where_write == SHORT)
        return (_vector_new(a->x - b->x, a->y - b->y, a->z - b->z));
    return (vector_new(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vector* vmult(t_vector *a, t_vector *b) {
    if (memory->where_write == SHORT)
        return (_vector_new(a->x * b->x, a->y * b->y, a->z * b->z));
    return (vector_new( a->x * b->x, a->y * b->y, a->z * b->z));
}


t_vector* vmultf(t_vector *a, float factor) {
    if (memory->where_write == SHORT)
        return (_vector_new(a->x * factor, a->y * factor, a->z * factor));
    return (vector_new(a->x * factor, a->y * factor, a->z * factor));
}


t_vector* vdivf(t_vector *a, float factor) {
    return (vmultf(a, 1 / factor));
}

t_vector* vector_new(float x, float y, float z) {

    t_vector* vector = (t_vector *) new(1, sizeof(t_vector), vector_free, LONG);

    vector->x = x;
    vector->y = y;
    vector->z = z;

    return (vector);
}

t_vector* _vector_new(float x, float y, float z) {
    t_vector* vector = (t_vector *) new(1, sizeof(t_vector), vector_free, SHORT);

    vector->x = x;
    vector->y = y;
    vector->z = z;

    return (vector);
}

void    vector_free(void *vector) {
    free(vector);
}
