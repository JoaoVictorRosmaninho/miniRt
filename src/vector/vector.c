#include "../../includes/minit_rt.h"

extern t_memory g_memory;

void    vector_write_color(t_vector *v, int out)
{ 
    ft_fprintf(out, "%d %d %d\n", (int)(v->x * 255), (int)(v->y * 255), (int)(v->z * 255));
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

t_vector* vneg(t_vector *vector) {
    return vector_new(0 - vector->x, 0 - vector->y, 0 - vector->z);
}

double vmagnitude(t_vector *vector) {
    return (sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}

t_vector*  vnormalize(t_vector *vector) {
    double m;

    m = vmagnitude(vector);
    return(vector_new(vector->x / m, vector->y / m, vector->z / m));
}

float dot(t_vector* a,  t_vector* b) {
    return (
          a->x * b->x
        + a->y * b->y
        + a->z * b->z 
    );
}

t_vector* vector_new(float x, float y, float z) {
    
    t_vector* vector = (t_vector *) new(1, sizeof(t_vector), g_memory.coliseu_id);

    vector->x = x;
    vector->y = y;
    vector->z = z;

    return (vector);
}

