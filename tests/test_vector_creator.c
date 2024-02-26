#include "utils.h"

extern t_memory g_memory;

void teardown(void) {
   memory_destroy();
}

Test(vector, vector_new)
{
    t_vector*   vector;

    vector  =   vector_new(1,2,3);

    cr_assert_float_eq(vector->x, 1.0, EPSILON);
    cr_assert_float_eq(vector->y, 2.0, EPSILON);
    cr_assert_float_eq(vector->z, 3.0, EPSILON);
}

Test(vector, vsum) 
{
    t_vector* v1; 
    t_vector* v2;
    t_vector* v3;

    v1 = vector_new(1,1,1); 
    v2 = vector_new(1,1,1);

    v3 = vsum(v1, v2);

    cr_assert_float_eq(v3->x, 2.0, EPSILON);
    cr_assert_float_eq(v3->y, 2.0, EPSILON);
    cr_assert_float_eq(v3->z, 2.0, EPSILON);

}

