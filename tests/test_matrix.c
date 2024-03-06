#include "utils.h"

extern t_memory g_memory;

void setup(void) {
    g_memory.memory[LONG].door   = NULL;
    g_memory.memory[LONG].region = NULL;
    g_memory.memory[LONG].size   = ARENA_8KB;
    g_memory.coliseu = LONG;
}

void teardown(void) {
    ft_arena_destroy(&g_memory.memory[LONG]);
}

Test(matrix, matrix_new_align, .init = setup, .fini = teardown)
{
    t_matrix* m = matrix_new(3, 3);

    unsigned char result = m->lines[0] <  m->lines[1];
    cr_expect(result == 1, "0 align");

    result = m->lines[1] <  m->lines[2];
    cr_expect(result == 1, "0 align");

    result = *m->lines !=  *(m->lines + 1);
    cr_expect(result == 1, "0 align");

    result =  *(m->lines + 1) != *(m->lines + 2);
    cr_expect(result == 1, "0 align");
}
Test(matrix, matrix_fill, .init = setup, .fini = teardown)
{
    t_matrix* m = matrix_new(3, 3);


    m->lines[0][0] = 10.0;
    m->lines[0][1] = 11.0;
    m->lines[0][2] = 12.0;

    m->lines[1][0] = 24.0;
    m->lines[1][1] = 25.0;
    m->lines[1][2] = 26.0;

    m->lines[2][0] = 27.0;
    m->lines[2][1] = 28.0;
    m->lines[2][2] = 29.0;

    cr_assert_float_eq(m->lines[0][0], 10.0, EPSILON);
    cr_assert_float_eq(m->lines[0][1], 11.0, EPSILON);
    cr_assert_float_eq(m->lines[0][2], 12.0, EPSILON);
    
    cr_assert_float_eq(m->lines[2][0], 27.0, EPSILON);
    cr_assert_float_eq(m->lines[2][1], 28.0, EPSILON);
    cr_assert_float_eq(m->lines[2][2], 29.0, EPSILON);
}

Test(matrix, matrix_eq, .init = setup, .fini = teardown)
{
    t_matrix* m = matrix_new(3, 3);
    t_matrix* m2 = matrix_new(3, 3);


    m->lines[0][0] = 10.0;
    m->lines[0][1] = 11.0;
    m->lines[0][2] = 12.0;

    m->lines[1][0] = 24.0;
    m->lines[1][1] = 25.0;
    m->lines[1][2] = 26.0;

    m->lines[2][0] = 27.0;
    m->lines[2][1] = 28.0;
    m->lines[2][2] = 29.0;

    m2->lines[0][0] = 10.0;
    m2->lines[0][1] = 11.0;
    m2->lines[0][2] = 12.0;

    m2->lines[1][0] = 24.0;
    m2->lines[1][1] = 25.0;
    m2->lines[1][2] = 26.0;

    m2->lines[2][0] = 27.0;
    m2->lines[2][1] = 28.0;
    m2->lines[2][2] = 29.0;

    unsigned int eq = matrix_eq(m, m2, 3, 3);
    cr_assert_float_eq(eq, 1.0, EPSILON);
}

Test(matrix, matrix_eq_diff, .init = setup, .fini = teardown)
{
    t_matrix* m = matrix_new(3, 3);
    t_matrix* m2 = matrix_new(3, 3);


    m->lines[0][0] = 10.0;
    m->lines[0][1] = 11.0;
    m->lines[0][2] = 12.0;

    m->lines[1][0] = 24.0;
    m->lines[1][1] = 25.0;
    m->lines[1][2] = 26.0;

    m->lines[2][0] = 27.0;
    m->lines[2][1] = 28.0;
    m->lines[2][2] = 29.0;

    m2->lines[0][0] = 13.0;
    m2->lines[0][1] = 14.0;
    m2->lines[0][2] = 15.0;

    m2->lines[1][0] = 24.0;
    m2->lines[1][1] = 25.0;
    m2->lines[1][2] = 26.0;

    m2->lines[2][0] = 27.0;
    m2->lines[2][1] = 28.0;
    m2->lines[2][2] = 29.0;

    unsigned int eq = matrix_eq(m, m2, 3, 3);
    cr_assert_float_eq(eq, 0.0, EPSILON);
}

Test(matrix, matrix_eq_multiply, .init = setup, .fini = teardown)
{
    t_matrix* m  = matrix_new(4, 4);
    t_matrix* m2 = matrix_new(4, 4);


    m->lines[0][0] = 1.0;
    m->lines[0][1] = 2.0;
    m->lines[0][2] = 3.0;
    m->lines[0][3] = 4.0;
    
    m->lines[1][0] = 5.0;
    m->lines[1][1] = 6.0;
    m->lines[1][2] = 7.0;
    m->lines[1][3] = 8.0;

    m->lines[2][0] = 9.0;
    m->lines[2][1] = 8.0;
    m->lines[2][2] = 7.0;
    m->lines[2][3] = 6.0;

    m->lines[3][0] = 5.0;
    m->lines[3][1] = 4.0;
    m->lines[3][2] = 3.0;
    m->lines[3][3] = 2.0;

    m2->lines[0][0] = -2.0;
    m2->lines[0][1] = 1.0;
    m2->lines[0][2] = 2.0;
    m2->lines[0][3] = 3.0;

    m2->lines[1][0] = 3.0;
    m2->lines[1][1] = 2.0;
    m2->lines[1][2] = 1.0;
    m2->lines[1][3] = -1.0;

    m2->lines[2][0] = 4.0;
    m2->lines[2][1] = 3.0;
    m2->lines[2][2] = 6.0;
    m2->lines[2][3] = 5.0;

    m2->lines[3][0] = 1.0;
    m2->lines[3][1] = 2.0;
    m2->lines[3][2] = 7.0;
    m2->lines[3][3] = 8.0;

    t_matrix* r = matrix_mult(m, m2);

    cr_assert_float_eq(r->lines[0][0], 20.0, EPSILON);
    cr_assert_float_eq(r->lines[0][1], 22.0, EPSILON);

    cr_assert_float_eq(r->lines[0][2], 50.0, EPSILON);
    cr_assert_float_eq(r->lines[0][3], 48.0, EPSILON);

    cr_assert_float_eq(r->lines[1][0], 44.0, EPSILON);
    cr_assert_float_eq(r->lines[1][1], 54.0, EPSILON);
    cr_assert_float_eq(r->lines[1][2], 114.0, EPSILON);
    cr_assert_float_eq(r->lines[1][3], 108.0, EPSILON);

    cr_assert_float_eq(r->lines[2][0], 40.0, EPSILON);
    cr_assert_float_eq(r->lines[2][1], 58.0, EPSILON);
    cr_assert_float_eq(r->lines[2][2], 110.0, EPSILON);
    cr_assert_float_eq(r->lines[2][3], 102.0, EPSILON);

    cr_assert_float_eq(r->lines[3][0], 16.0, EPSILON);
    cr_assert_float_eq(r->lines[3][1], 26.0, EPSILON);
    cr_assert_float_eq(r->lines[3][2], 46.0, EPSILON);
    cr_assert_float_eq(r->lines[3][3], 42.0, EPSILON);
}

Test(matrix, matrix_mult_tuple, .init = setup, .fini = teardown)
{
    t_matrix* m  = matrix_new(4, 4);
    t_matrix* m2 = matrix_new(4, 1);


    m->lines[0][0] = 1.0;
    m->lines[0][1] = 2.0;
    m->lines[0][2] = 3.0;
    m->lines[0][3] = 4.0;
    
    m->lines[1][0] = 2.0;
    m->lines[1][1] = 4.0;
    m->lines[1][2] = 4.0;
    m->lines[1][3] = 2.0;

    m->lines[2][0] = 8.0;
    m->lines[2][1] = 6.0;
    m->lines[2][2] = 4.0;
    m->lines[2][3] = 1.0;

    m->lines[3][0] = 0.0;
    m->lines[3][1] = 0.0;
    m->lines[3][2] = 0.0;
    m->lines[3][3] = 1.0;

    m2->lines[0][0] = 1.0;
    m2->lines[0][1] = 2.0;
    m2->lines[0][2] = 3.0;
    m2->lines[0][3] = 1.0;


    t_matrix* r = matrix_mult(m, m2);

    cr_assert_float_eq(r->lines[0][0], 18.0, EPSILON);
    cr_assert_float_eq(r->lines[1][0], 24.0, EPSILON);
    cr_assert_float_eq(r->lines[2][0], 33.0, EPSILON);
    cr_assert_float_eq(r->lines[3][0], 1.0, EPSILON);
}

Test(matrix, matrix_transpose, .init = setup, .fini = teardown)
{
    t_matrix* m  = matrix_new(4, 4);


    m->lines[0][0] = 1.0;
    m->lines[0][1] = 2.0;
    m->lines[0][2] = 3.0;
    m->lines[0][3] = 4.0;
    
    m->lines[1][0] = 2.0;
    m->lines[1][1] = 4.0;
    m->lines[1][2] = 4.0;
    m->lines[1][3] = 2.0;

    m->lines[2][0] = 8.0;
    m->lines[2][1] = 6.0;
    m->lines[2][2] = 4.0;
    m->lines[2][3] = 1.0;

    m->lines[3][0] = 0.0;
    m->lines[3][1] = 0.0;
    m->lines[3][2] = 0.0;
    m->lines[3][3] = 1.0;

    t_matrix* r = matrix_transpose(m);

    cr_assert_float_eq(matrix_get(0,0, r), 1.0, EPSILON);
    cr_assert_float_eq(matrix_get(1,0, r), 2.0, EPSILON);
    cr_assert_float_eq(matrix_get(2,0, r), 3.0, EPSILON);
    cr_assert_float_eq(matrix_get(3,0, r), 4.0, EPSILON);

}

Test(matrix, matrix22_determiant, .init = setup, .fini = teardown) {
    t_matrix* m =  matrix_new(2,2);

    m->lines[0][0] =  1;
    m->lines[0][1] = 5;
    
    m->lines[1][0] = -3;
    m->lines[1][1] = 2;

    cr_assert_float_eq(matrix22_determiant(m), 17.0, EPSILON);

}

Test(matrix, matrix_submatrix, .init = setup, .fini = teardown)  {
    t_matrix* m = matrix_new(3,3);

    m->lines[0][0] = 1.0;
    m->lines[0][1] = 5.0;
    m->lines[0][2] = 0.0;

    m->lines[1][0] = -3.0;
    m->lines[1][1] =  2.0;
    m->lines[1][2] =  7.0;

    m->lines[2][0] = 0.0;
    m->lines[2][1] = 6.0;
    m->lines[2][2] = -3.0;

    t_matrix  *r = matrix_submatrix(m, 0, 2);


    cr_assert_float_eq(r->rows, 2, EPSILON);
    cr_assert_float_eq(r->cols, 2, EPSILON);

    cr_assert_float_eq(r->lines[0][0], -3, EPSILON);
    cr_assert_float_eq(r->lines[0][1],  2, EPSILON);
    cr_assert_float_eq(r->lines[1][0],  0, EPSILON);
    cr_assert_float_eq(r->lines[1][1],  6, EPSILON);
}

Test(matrix, matrix_submatrix2, .init = setup, .fini = teardown)  {
    t_matrix* m = matrix_new(3,3);

    m->lines[0][0] = 3.0;
    m->lines[0][1] = 5.0;
    m->lines[0][2] = 0.0;

    m->lines[1][0] = -2.0;
    m->lines[1][1] =  -1.0;
    m->lines[1][2] =  -7.0;

    m->lines[2][0] =  6.0;
    m->lines[2][1] = -1.0;
    m->lines[2][2] =  5.0;


    t_matrix* s = matrix_submatrix(m, 1 ,  0);

    cr_assert_float_eq(s->lines[0][0], 5, EPSILON);
    cr_assert_float_eq(s->lines[0][1], 0, EPSILON);
    cr_assert_float_eq(s->lines[1][0], -1, EPSILON);
    cr_assert_float_eq(s->lines[1][1], 5, EPSILON);
}

Test(matrix, matrix_minor, .init = setup, .fini = teardown)  {
    t_matrix* m = matrix_new(3,3);

    m->lines[0][0] = 3.0;
    m->lines[0][1] = 5.0;
    m->lines[0][2] = 0.0;

    m->lines[1][0] = -2.0;
    m->lines[1][1] =  -1.0;
    m->lines[1][2] =  -7.0;

    m->lines[2][0] =  6.0;
    m->lines[2][1] = -1.0;
    m->lines[2][2] =  5.0;

    double r = matrix_minor(m, 1, 0);
    cr_assert_float_eq(r, 25, EPSILON);
}

Test(matrix, matrix_cofactor, .init = setup, .fini = teardown)  {
    t_matrix* m = matrix_new(3,3);

    m->lines[0][0] = 3.0;
    m->lines[0][1] = 5.0;
    m->lines[0][2] = 0.0;

    m->lines[1][0] = -2.0;
    m->lines[1][1] =  -1.0;
    m->lines[1][2] =  -7.0;

    m->lines[2][0] =  6.0;
    m->lines[2][1] = -1.0;
    m->lines[2][2] =  5.0;

    cr_assert_float_eq(matrix_minor(m, 0, 0), -12, EPSILON);
    cr_assert_float_eq(matrix_minor(m, 1, 0), 25, EPSILON);
    
    cr_assert_float_eq(matrix_cofactor(m, 0, 0), -12, EPSILON);
    cr_assert_float_eq(matrix_cofactor(m, 1, 0), -25, EPSILON);
}

Test(matrix, matrix_determinant, .init = setup, .fini = teardown)  {
    t_matrix* m = matrix_new(3,3);

    m->lines[0][0] = 1.0;
    m->lines[0][1] = 2.0;
    m->lines[0][2] = 6.0;

    m->lines[1][0] = -5.0;
    m->lines[1][1] =  8.0;
    m->lines[1][2] = -4.0;

    m->lines[2][0] =  2.0;
    m->lines[2][1] =  6.0;
    m->lines[2][2] =  4.0;

    cr_assert_float_eq(matrix_determinant(m), -196.0, EPSILON);
}
Test(matrix, matrix_inversible_tests, .init = setup, .fini = teardown) {

    t_matrix* m = matrix_new(4,4);


    m->lines[0][0] = 6;
    m->lines[0][1] = 4;
    m->lines[0][2] = 4;
    m->lines[0][3] = 4;
   
    m->lines[1][0] = 5;
    m->lines[1][1] = 5;
    m->lines[1][2] = 7;
    m->lines[1][3] = 6;

    m->lines[2][0] = 4;
    m->lines[2][1] = -9;
    m->lines[2][2] = 3;
    m->lines[2][3] = -7;

    m->lines[3][0] = 9;
    m->lines[3][1] = 1;
    m->lines[3][2] = 7;
    m->lines[3][3] = -6;

    t_matrix* a1 = matrix_submatrix(m, 0, 0);

    cr_assert_float_eq(a1->rows, 3, EPSILON);
    cr_assert_float_eq(a1->cols, 3, EPSILON);
    

    cr_assert_float_eq(a1->lines[0][0], 5, EPSILON);
    cr_assert_float_eq(a1->lines[0][1], 7, EPSILON);
    cr_assert_float_eq(a1->lines[0][2], 6, EPSILON);
    
    cr_assert_float_eq(a1->lines[1][0], -9, EPSILON);
    cr_assert_float_eq(a1->lines[1][1],  3, EPSILON);
    cr_assert_float_eq(a1->lines[1][2], -7, EPSILON);

    cr_assert_float_eq(a1->lines[2][0],  1, EPSILON);
    cr_assert_float_eq(a1->lines[2][1],  7, EPSILON);
    cr_assert_float_eq(a1->lines[2][2], -6, EPSILON);

    double d = matrix_determinant(m);
    cr_assert_float_eq(d, -2120, EPSILON);

//
   // cr_log_info("Det: %f\n", d);
}
