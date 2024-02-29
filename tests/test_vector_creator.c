#include "utils.h"

extern t_memory g_memory;

void setup(void) {
    g_memory.memory[LONG].door   = NULL;
    g_memory.memory[LONG].region = NULL;
    g_memory.memory[LONG].size   = ARENA_256B;
    g_memory.coliseu_id = LONG;
}

void teardown(void) {
    ft_arena_destroy(&g_memory.memory[LONG]);
}

Test(vector, vector_new, .init = setup, .fini = teardown)
{
    t_vector*   vector;

    vector  =   vector_new(1,2,3);

    cr_assert_float_eq(vector->x, 1.0, EPSILON);
    cr_assert_float_eq(vector->y, 2.0, EPSILON);
    cr_assert_float_eq(vector->z, 3.0, EPSILON);
}

Test(vector, vsum, .init = setup, .fini = teardown) 
{

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
    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(3,-2,5); 
        v2 = vector_new(-2,3,1);

        v3 = vsum(v1, v2);

        cr_assert_float_eq(v3->x, 1.0, EPSILON);
        cr_assert_float_eq(v3->y, 1.0, EPSILON);
        cr_assert_float_eq(v3->z, 6.0, EPSILON);
    }
}

Test(vector, vsub, .init = setup, .fini = teardown) 
{

    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(3,2,1); 
        v2 = vector_new(5,6,7);

        v3 = vsub(v1, v2);

        cr_assert_float_eq(v3->x, -2.0, EPSILON);
        cr_assert_float_eq(v3->y, -4.0, EPSILON);
        cr_assert_float_eq(v3->z, -6.0, EPSILON);

    }
    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(3,2,1); 
        v2 = vector_new(5,6,7);

        v3 = vsub(v1, v2);

        cr_assert_float_eq(v3->x, -2.0, EPSILON);
        cr_assert_float_eq(v3->y, -4.0, EPSILON);
        cr_assert_float_eq(v3->z, -6.0, EPSILON);
    }
}


