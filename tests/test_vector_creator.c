#include "utils.h"

t_coliseu coliseu = {
    .door = NULL,
    .region = NULL,
    .size = ARENA_16KB
};

void setup(void) {

}

void teardown(void) {
    ft_arena_destroy(&coliseu);
}

Test(vector, vector_new, .init = setup, .fini = teardown)
{
    t_vector*   vector;

    vector  =   vector_new(1,2,3);

    cr_assert_float_eq(vector->lines[0][X], 1.0, EPSILON);
    cr_assert_float_eq(vector->lines[0][Y], 2.0, EPSILON);
    cr_assert_float_eq(vector->lines[0][Z], 3.0, EPSILON);
}

Test(vector, vsum, .init = setup, .fini = teardown) 
{

    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(1,1,1); 
        v2 = vector_new(1,1,1);

        v3 = vsum(v1, v2, &coliseu);

        cr_assert_float_eq(v3->lines[0][X], 2.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Y], 2.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Z], 2.0, EPSILON);

    }
    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(3,-2,5); 
        v2 = vector_new(-2,3,1);

        v3 = vsum(v1, v2, &coliseu);

        cr_assert_float_eq(v3->lines[0][X], 1.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Y], 1.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Z], 6.0, EPSILON);
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

        v3 = vsub(v1, v2, &coliseu);

        cr_assert_float_eq(v3->lines[0][X], -2.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Y], -4.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Z], -6.0, EPSILON);

    }
    {
        t_vector* v1; 
        t_vector* v2;
        t_vector* v3;
        v1 = vector_new(3,2,1); 
        v2 = vector_new(5,6,7);

        v3 = vsub(v1, v2, &coliseu);

        cr_assert_float_eq(v3->lines[0][X], -2.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Y], -4.0, EPSILON);
        cr_assert_float_eq(v3->lines[0][Z], -6.0, EPSILON);
    }
}

Test(vector, vneg, .init = setup, .fini = teardown) 
{
    t_vector *zero = vector_new(1.0,2.0,3.0);

    t_vector* result = vneg(zero, &coliseu);

    cr_assert_float_eq(result->lines[0][X], -1.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Y], -2.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Z], -3.0, EPSILON);
}
Test(vector, vmultf, .init = setup, .fini = teardown) 
{
    t_vector *zero = vector_new(1.0,2.0,3.0);

    t_vector* result = vmultf(zero, 3.5);

    cr_assert_float_eq(result->lines[0][X], 3.5, EPSILON);
    cr_assert_float_eq(result->lines[0][Y], 7.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Z], 10.5, EPSILON);

    zero   = vector_new(-1, -2, -4);
    result = vmultf(zero, 0.5);

    cr_assert_float_eq(result->lines[0][X], -0.5, EPSILON);
    cr_assert_float_eq(result->lines[0][Y], -1.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Z], -2.0, EPSILON);

}

Test(vector, vmagnitude, .init = setup, .fini = teardown)  {
    t_vector* v1 = vector_new(1,0,0);
    t_vector* v2 = vector_new(-1,-2,-3);

    cr_assert_float_eq(vmagnitude(v1), 1.0, EPSILON);
    cr_assert_float_eq(vmagnitude(v2), sqrt(14), EPSILON);
}

Test(vector, vnormalize, .init = setup, .fini = teardown)  {
    t_vector* v1 = vector_new(4,0,0);
    t_vector* v2 = vector_new(1,2,3);

    t_vector* result = vnormalize(v1, &coliseu);

    cr_assert_float_eq(result->lines[0][X], 1.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Y], 0.0, EPSILON);
    cr_assert_float_eq(result->lines[0][Z], 0.0, EPSILON);

    result = vnormalize(v2);
    cr_assert_float_eq(result->lines[0][X], 1.0/sqrt(14.0), EPSILON);
    cr_assert_float_eq(result->lines[0][Y], 2.0/sqrt(14.0), EPSILON);
    cr_assert_float_eq(result->lines[0][Z], 3.0/sqrt(14.0), EPSILON);

    result = vnormalize(vector_new(1,2,3), &coliseu);

    cr_assert_float_eq(vmagnitude(result), 1.0, EPSILON);
}

Test(vector, vdot, .init = setup, .fini = teardown) {
    cr_assert_float_eq(vdot(vector_new(1,2,3), vector_new(2,3,4)), 20.0, EPSILON);
}

Test(vector, vcross, .init = setup, .fini = teardown) {
    
    t_vector* r = vcross(vector_new(1,2,3), vector_new(2,3,4), &coliseu);

    cr_assert_float_eq(r->lines[0][X], -1.0, EPSILON);
    cr_assert_float_eq(r->lines[0][Y],  2.0, EPSILON);
    cr_assert_float_eq(r->lines[0][Z], -1.0, EPSILON);
    
    r = vcross(vector_new(2,3,4), vector_new(1,2,3), &coliseu);

    cr_assert_float_eq(r->lines[0][X], 1.0, EPSILON);
    cr_assert_float_eq(r->lines[0][Y], -2.0, EPSILON);
    cr_assert_float_eq(r->lines[0][Z], 1.0, EPSILON);
}




