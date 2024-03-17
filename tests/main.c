#include "utils.h"

int main(void) {

   t_coliseu coliseu = {
        .door = NULL,
        .region = NULL,
        .size = ARENA_16KB
    };

    t_point2* point = point_new(1,0,1, &coliseu);

    t_matrix* rotation    = rotation_x(M_PI / 2, &coliseu);

    t_matrix* scaling     = scale_new(5,5,5, &coliseu);

    t_matrix* translation = translation_new(10,5,7, &coliseu);

    t_point2* r  = matrix_mult(rotation, point, &coliseu);
    r            = matrix_mult(scaling,  r, &coliseu);    
    t_point2*  r2 = matrix_mult(translation, r, &coliseu);    

    print_matrix(rotation);
    putchar('\n');
    print_matrix(scaling);
    putchar('\n');
    print_matrix(translation);
    putchar('\n');
    print_matrix(r2);
    ft_arena_destroy(&coliseu);
}