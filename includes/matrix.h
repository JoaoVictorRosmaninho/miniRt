#ifndef MATRIX_H
# define MATRIX_H
# include "./minit_rt.h"

typedef struct s_matrix {
    unsigned short int rows;
    unsigned short int cols;
    double **lines;
} t_matrix;

t_matrix* matrix_new(unsigned short int rows, unsigned short int cols);

uint8_t matrix_eq(t_matrix* a, t_matrix* b, unsigned int row, unsigned int col);

t_matrix* matrix_mult(t_matrix* a, t_matrix* b);

t_matrix* matrix_transpose(t_matrix *m);

double matrix_get(unsigned short r, unsigned short c, t_matrix* m);

double matrix22_determiant(t_matrix *m);

t_matrix* matrix_submatrix(t_matrix *m, unsigned short int row, unsigned short int col) ;

double matrix_minor(t_matrix* m, unsigned short row, unsigned short col);

double matrix_cofactor(t_matrix *a, unsigned short row, unsigned short col);

double matrix_determinant(t_matrix* m);

unsigned char matrix_reversible(t_matrix *m) ;

#endif