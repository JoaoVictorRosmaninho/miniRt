#ifndef UTILS_H
# define UTILS_H

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

# include <stdio.h>
# include <math.h>

# include "../includes/minit_rt.h"

# define EPSILON 0.00001
# define BLACK new_color(0, 0, 0)
# define WHITE new_color(1, 1, 1)



void print_matrix(t_matrix* m) {
    for(unsigned short int i = 0; i < m->rows; i++) {
        for(unsigned short int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->lines[i][j]);
        }
        putchar('\n');
    }
}

#endif