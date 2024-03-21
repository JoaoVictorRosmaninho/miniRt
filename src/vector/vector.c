#include "../../includes/minit_rt.h"

void  vector_write_color(t_color* v, int out)
{ 

    (void)(out);
    ft_fprintf(out, "%d %d %d ", (int)(v->x * 255), (int)(v->y * 255), (int)(v->z * 255));
}

unsigned char vector_equals(t_vector2* a, t_vector2* b)
{
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);

    return (v1[X] == v2[X] && v1[Y] == v2[Y] && v1[Z] == v2[Z]);
}

void vector_to_str(t_vector2 *v) {
    double* v1 = *(v->lines);
    printf("X: %f, Y: %f, Z: %f\n", v1[X], v1[Y], v1[Z]);
}

t_vector* vsum(t_vector2 *a, t_vector2 *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new2(v1[X] + v2[X], v1[Y] + v2[Y], v1[Z] + v2[Z], coliseu));
}

t_vector* vsub(t_vector2 *a, t_vector2 *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new2(v1[X] - v2[X], v1[Y] - v2[Y], v1[Z] - v2[Z], coliseu));
}

t_vector* vmult(t_vector2 *a, t_vector2 *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new2(v1[X] * v2[X], v1[Y] * v2[Y], v1[Z] * v2[Z], coliseu));
}


t_vector* vmultf(t_vector2 *a, float factor) {
    double* v1;

    v1  = *(a->lines);
    return (vector_new(v1[X] * factor, v1[Y] * factor, v1[Z] * factor));
}


t_vector* vdivf(t_vector2 *a, float factor) {
    return (vmultf(a, 1.0 / factor));
}

t_vector* vneg(t_vector2 *a, t_coliseu* coliseu) {
    double* v1;

    v1  = *(a->lines);
    return vector_new2(0 - v1[X], 0 - v1[Y], 0 - v1[Z], coliseu);
}

double vmagnitude(t_vector *vector) {
    return (sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}

t_vector*  vnormalize(t_vector *vector) {
    double m;

    m = vmagnitude(vector);
    return(vector_new(vector->x / m, vector->y / m, vector->z / m));
}

double vdot(t_vector* a,  t_vector* b) {
    return (
          a->x * b->x
        + a->y * b->y
        + a->z * b->z 
    );
}

t_vector* vcross(t_vector* a, t_vector* b) {
    return vector_new(
        a->y * b->z - a->z * b->y,
        a->z * b->x - a->x * b->z,
        a->x * b->y - a->y * b->x
    );
}

t_vector* vector_new(double x, double y, double z) {
    
    t_vector* vector = (t_vector *) new(1, sizeof(t_vector), NULL);

    vector->x = x;
    vector->y = y;
    vector->z = z;

    return (vector);
}

t_vector2* vector_new2(double x, double y, double z, t_coliseu*  coliseu) {
    
    t_vector2* vector;

    vector = matrix_new(4,1, coliseu);

    vector->lines[X][0] = x;
    vector->lines[Y][0] = y;
    vector->lines[Z][0] = z;
    vector->lines[W][0] = 1;


    return (vector);
}

