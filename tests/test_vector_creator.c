#include "utils.h"


void teardown(void) {
    ft_printf("FInalizando\n");
}

Test(vector, vector_new)
{
    t_vector*   vector;

    vector  =   vector_new(1,2,3);

    cr_assert_float_eq(vector->x, 1.0, EPSILON);
    cr_assert_float_eq(vector->y, 2.0, EPSILON);
    cr_assert_float_eq(vector->z, 3.0, EPSILON);

}

