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

Test(matrix, translate, .init = setup, .fini = teardown) {

    t_point2* p =  point_new(-3, 4, 5, &coliseu);   //   matrix_new(4, 1, &coliseu);

    t_matrix* t = translation_new(5, -3, 2, &coliseu);

    t_point2* result = matrix_mult(t, p, &coliseu);

    cr_assert_float_eq(result->lines[0][0], -3, EPSILON);
    cr_assert_float_eq(result->lines[1][0],  4, EPSILON);
    cr_assert_float_eq(result->lines[2][0],  5, EPSILON);
}

Test(matrix, translate_unsing_inverse, .init = setup, .fini = teardown) {

    t_point2* p = matrix_new(1, 4, &coliseu);

    p->lines[0][0] = -3;
    p->lines[0][1] =  4;
    p->lines[0][2] =  5;

    t_matrix* t = translation_new(5, -3, 2, &coliseu);

    t = matrix_reverse(t, &coliseu);

    t_point2* result = translation_transform(t, p, &coliseu);

    cr_assert_float_eq(result->lines[0][0], -8, EPSILON);
    cr_assert_float_eq(result->lines[0][1], 7, EPSILON);
    cr_assert_float_eq(result->lines[0][2], 3, EPSILON);
}
Test(matrix, scale, .init = setup, .fini = teardown) {

    t_point2* p = point_new(-4,6,8, &coliseu);

    cr_assert(p->rows == 4, "Ter 4  linhas");
    cr_assert(p->cols == 1, "Ter 1  coluna");

    t_matrix* t = scale_new(2, 3, 4, &coliseu);

    cr_assert(t->rows == 4, "Ter 4  linhas");
    cr_assert(t->cols == 4, "Ter 4  colunas");

    t_point2* result =  matrix_mult(t, p, &coliseu);
    
    cr_assert(result != NULL, "expect a valid matrice");

    cr_assert_float_eq(result->lines[0][0], -8, EPSILON);
    cr_assert_float_eq(result->lines[1][0], 18, EPSILON);
    cr_assert_float_eq(result->lines[2][0], 32, EPSILON);
}

Test(matrix, scale_vector, .init = setup, .fini = teardown) {

    t_vector* p = point_new(-4,6,8, &coliseu);

    t_matrix* t = scale_new(2, 3, 4, &coliseu);

    t_vector* result = matrix_mult(t, p, &coliseu);

    cr_assert_float_eq(result->lines[0][0], -8, EPSILON);
    cr_assert_float_eq(result->lines[0][1], 18, EPSILON);
    cr_assert_float_eq(result->lines[0][2], 32, EPSILON);
}

Test(matrix, scale_vector_inverse, .init = setup, .fini = teardown) {

    t_vector* p = point_new(-4,6,8, &coliseu);

    p->lines[0][0] = -4;
    p->lines[0][1] =  6;
    p->lines[0][2] =  8;

    t_matrix* t = scale_new(2, 3, 4, &coliseu);

    t = matrix_reverse(t, &coliseu);

    t_vector* result = matrix_mult(t, p, &coliseu);

    cr_assert_float_eq(result->lines[0][0], -2, EPSILON);
    cr_assert_float_eq(result->lines[0][1], 2, EPSILON);
    cr_assert_float_eq(result->lines[0][2], 2, EPSILON);
}

Test(matrix, reflection, .init = setup, .fini = teardown) {

    // reflection is scaling with negative values 

    t_vector* p = point_new(2,3,4, &coliseu);

    p->lines[0][0] =  2;
    p->lines[0][1] =  3;
    p->lines[0][2] =  4;

    t_matrix* t = scale_new(-1, 1, 1, &coliseu);

    t_vector* result = matrix_mult(t, p, &coliseu);

    cr_assert_float_eq(result->lines[0][0], -2, EPSILON);
    cr_assert_float_eq(result->lines[0][1],  3, EPSILON);
    cr_assert_float_eq(result->lines[0][2],  4, EPSILON);
}


Test(matrix, quarters, .init = setup, .fini = teardown) {

  double a = M_PI / 2.0;

  t_matrix* full_quater = rotation_x(a, &coliseu);

  cr_assert_float_eq(full_quater->lines[1][1], cos(a), EPSILON);
  cr_assert_float_eq(full_quater->lines[1][2], -sin(a), EPSILON);
  cr_assert_float_eq(full_quater->lines[2][1], sin(a), EPSILON);
  cr_assert_float_eq(full_quater->lines[2][2], cos(a), EPSILON);

}


Test(matrix, rotation_full_quarter, .init = setup, .fini = teardown) {
    
    t_vector* p = point_new(0,1,0, &coliseu);
    
    t_matrix* full_quater = rotation_x(M_PI / 2.0, &coliseu);


    t_vector* point_i = matrix_mult(full_quater, p, &coliseu);

   cr_assert_float_eq(point_i->lines[0][0], 0.0, EPSILON);
   cr_assert_float_eq(point_i->lines[1][0], 0.0, EPSILON);
   cr_assert_float_eq(point_i->lines[2][0], 1.0, EPSILON);

}
Test(matrix, rotation_half_quarter, .init = setup, .fini = teardown) {
    
    t_vector* p = point_new(0,1,0, &coliseu);

    t_matrix* half_quarter = rotation_x(M_PI / 4.0, &coliseu);

    t_vector* point_i = matrix_mult(half_quarter,p, &coliseu);
    
    cr_assert_float_eq(point_i->lines[0][0], 0.0, EPSILON);
    cr_assert_float_eq(point_i->lines[1][0], sqrt(2)/2, EPSILON);
    cr_assert_float_eq(point_i->lines[2][0], sqrt(2)/2, EPSILON);
}

Test(matrix, rotation_half_quarter_inverse, .init = setup, .fini = teardown) {
    
    t_vector* p = point_new(0,1,0, &coliseu);
    p->lines[0][0] =  0;
    p->lines[0][1] =  1;
    p->lines[0][2] =  0;

    t_matrix* half_quarter = rotation_x(M_PI / 4.0, &coliseu);

    half_quarter = matrix_reverse(half_quarter, &coliseu);

    t_vector* point_i = matrix_mult(half_quarter, p,  &coliseu);
    
    cr_assert_float_eq(point_i->lines[0][0], 0.0, EPSILON);
    cr_assert_float_eq(point_i->lines[1][0], sqrt(2)/2, EPSILON);
    cr_assert_float_eq(point_i->lines[2][0], -sqrt(2)/2, EPSILON);
}

Test(matrix, rotation_half_quarter_inverse_y, .init = setup, .fini = teardown) {
    
    t_vector* p = point_new(0,0,1, &coliseu);
    t_matrix* half_quarter = rotation_y(M_PI / 4.0, &coliseu);

    t_vector* point_i = matrix_mult(half_quarter, p, &coliseu);
    

    cr_assert_float_eq(point_i->lines[0][0], sqrt(2)/2, EPSILON);
    cr_assert_float_eq(point_i->lines[1][0], 0.0, EPSILON);
    cr_assert_float_eq(point_i->lines[2][0], sqrt(2)/2, EPSILON);
}

Test(matrix, rotation_z, .init = setup, .fini = teardown) {
    
    t_vector* p = point_new(0,1,0,&coliseu);

    t_matrix* half_quarter = rotation_z(M_PI / 4.0, &coliseu);


    t_vector* point_half  = matrix_mult(half_quarter, p, &coliseu);

    cr_assert_float_eq(point_half->lines[0][0], -sqrt(2)/2, EPSILON);
    cr_assert_float_eq(point_half->lines[1][0], sqrt(2)/2, EPSILON);
    cr_assert_float_eq(point_half->lines[2][0], 0.0, EPSILON);
    


    t_matrix*  full_quarter = rotation_z(M_PI / 2.0, &coliseu);
    t_vector* point_full   = matrix_mult(full_quarter, p, &coliseu);
    
    cr_assert_float_eq(point_full->lines[0][0], -1, EPSILON);
    cr_assert_float_eq(point_full->lines[1][0], 0, EPSILON);
    cr_assert_float_eq(point_full->lines[2][0], 0.0, EPSILON);
}


Test(matrix, shearing, .init = setup, .fini = teardown) {
    t_point2* point = point_new(2,3,4, &coliseu);

    double values[] = {1,0,0,0,0,0};

    t_matrix* s = shearing(values, &coliseu);

    t_matrix* r = matrix_mult(s, point, &coliseu);

    cr_assert_float_eq(r->lines[X][0], 5.0, EPSILON);
    cr_assert_float_eq(r->lines[Y][0], 3.0, EPSILON);
    cr_assert_float_eq(r->lines[Z][0], 4.0, EPSILON);
}

Test(matrix, shearing_test2, .init = setup, .fini = teardown) {
    t_point2* point = point_new(2,3,4, &coliseu);

    double values[] = {0,1,0,0,0,0};

    t_matrix* s = shearing(values, &coliseu);

    t_matrix* r = matrix_mult(s, point, &coliseu);

    cr_assert_float_eq(r->lines[X][0], 6.0, EPSILON);
    cr_assert_float_eq(r->lines[Y][0], 3.0, EPSILON);
    cr_assert_float_eq(r->lines[Z][0], 4.0, EPSILON);
}

Test(matrix, multiple_operations_at_once, .init = setup, .fini = teardown) {
    t_vector* point = vector_new(1,0,1, &coliseu);

    t_matrix* rotation    = rotation_x(M_PI / 2, &coliseu);

    t_matrix* scaling     = scale_new(5,5,5, &coliseu);

    t_matrix* translation = translation_new(10,5,7, &coliseu);

    t_point2* r  = matrix_mult(rotation, point, &coliseu);
    r            = matrix_mult(scaling,  r, &coliseu);    
    r            = matrix_mult(translation, r, &coliseu);    

    cr_assert_float_eq(r->lines[0][0], 15.0, EPSILON);
    cr_assert_float_eq(r->lines[Y][0], 0.0, EPSILON);
    cr_assert_float_eq(r->lines[Z][0], 7.0, EPSILON);

}

Test(matrix, matrix_chain_multiplication, .init = setup, .fini = teardown) {
    t_vector* vector = vector_new(1, 0, 1, &coliseu);
    
    t_matrix* rotation    = rotation_x(M_PI / 2, &coliseu);
    t_matrix* scaling     = scale_new(5,5,5, &coliseu);
    t_matrix* translation = translation_new(10,5,7, &coliseu);

    t_vector* result = matrix_mult_chain(5, &coliseu, translation, scaling, rotation, vector);

    cr_assert_float_eq(result->lines[X][0], 15.0, EPSILON);
    cr_assert_float_eq(result->lines[Y][0], 0.0, EPSILON);
    cr_assert_float_eq(result->lines[Z][0], 7.0, EPSILON);

}
