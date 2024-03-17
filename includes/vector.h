#ifndef  VECTOR_H
# define VECTOR_H


typedef struct s_vector {
    double x;
    double y;
    double z;
} t_vector;

typedef t_matrix t_vector2;



t_vector2* vector_new2(double x, double y, double z, t_coliseu* coliseu);
t_vector* vsum(t_vector *a, t_vector *b);
t_vector* vsub(t_vector *a, t_vector *b);
t_vector* vmult(t_vector *a, t_vector *b);
t_vector* vmultf(t_vector *a, float factor);
t_vector* vdivf(t_vector *a, float factor);
t_vector* vector_new(double x, double y, double z);
t_vector  vector_new_stack(float x, float y, float z);
t_vector* vneg(t_vector *vector);
t_vector* vcross(t_vector* a, t_vector* b);
t_vector* vnormalize(t_vector *vector) ;
double    vdot(t_vector* a,  t_vector* b);
void      vector_free(void *vector);
void      vector_write_color(t_vector *v, int out);
void      vector_to_str(t_vector *v);
double    vsqrt(t_vector *a);
float     vsquared(t_vector *a);
double    vmagnitude(t_vector *vector);
uint8_t vector_equals(t_vector* a, t_vector*  b);
#endif