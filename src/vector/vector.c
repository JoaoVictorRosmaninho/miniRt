#include "../../includes/minit_rt.h"

void  vector_write_color(t_color* v, int out)
{ 
    double* c;

    c  = *(v->lines);

    ft_fprintf(out, "%d %d %d ", (int)(c[X] * 255), (int)(c[Y] * 255), (int)(c[Z] * 255));
}

unsigned char vector_equals(t_vector* a, t_vector* b)
{
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);

    return (v1[X] == v2[X] && v1[Y] == v2[Y] && v1[Z] == v2[Z]);
}

void vector_to_str(t_vector *v) {
    double* v1 = *(v->lines);
    printf("X: %f, Y: %f, Z: %f\n", v1[X], v1[Y], v1[Z]);
}

t_vector* vsum(t_vector *a, t_vector *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new(v1[X] + v2[X], v1[Y] + v2[Y], v1[Z] + v2[Z], coliseu));
}

t_vector* vsub(t_vector *a, t_vector *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new(v1[X] - v2[X], v1[Y] - v2[Y], v1[Z] - v2[Z], coliseu));
}

t_vector* vmult(t_vector *a, t_vector *b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (vector_new(v1[X] * v2[X], v1[Y] * v2[Y], v1[Z] * v2[Z], coliseu));
}


t_vector* vmultf(t_vector *a, float factor, t_coliseu* coliseu) {
    double* v1;

    v1  = *(a->lines);
    return (vector_new(v1[X] * factor, v1[Y] * factor, v1[Z] * factor, coliseu));
}


t_vector* vdivf(t_vector *a, float factor, t_coliseu* coliseu) {
    return (vmultf(a, 1.0 / factor, coliseu));
}

t_vector* vneg(t_vector *a, t_coliseu* coliseu) {
    double* v1;

    v1  = *(a->lines);
    return vector_new(0 - v1[X], 0 - v1[Y], 0 - v1[Z], coliseu);
}

double vmagnitude(t_vector *vector) {
    double* v1;

    v1  = *(vector->lines);

    return (sqrt(v1[X] * v1[X] + v1[Y] * v1[Y] + v1[Z] * v1[Z]));
}

t_vector*  vnormalize(t_vector *vector, t_coliseu* coliseu) {
    double m;
    double* v1;

    v1  = *(vector->lines);

    m = vmagnitude(vector);
    return(vector_new(v1[X] / m, v1[Y] / m, v1[Z] / m, coliseu));
}

double vdot(t_vector* a,  t_vector* b) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return (
          v1[X] * v2[X]
        + v1[Y] * v2[Y]
        + v1[Z] * v2[Z] 
    );
}

t_vector* vcross(t_vector* a, t_vector* b, t_coliseu* coliseu) {
    double* v1;
    double* v2;

    v1  = *(a->lines);
    v2  = *(b->lines);
    return vector_new(
        v1[Y] * v2[Z] - v1[Z] * v2[Y],
        v1[Z] * v2[X] - v1[X] * v2[Z],
        v1[X] * v2[Y] - v1[Y] * v2[X],
        coliseu
    );
}

t_vector* vector_new(double x, double y, double z, t_coliseu*  coliseu) {
    
    t_vector* vector;

    vector = matrix_new(4,1, coliseu);

    vector->lines[X][0] = x;
    vector->lines[Y][0] = y;
    vector->lines[Z][0] = z;
    vector->lines[W][0] = 1;


    return (vector);
}

