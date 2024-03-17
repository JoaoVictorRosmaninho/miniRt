#include "../../includes/minit_rt.h"

uint8_t matrix_eq(t_matrix* a, t_matrix* b, unsigned int row, unsigned int col) {
    unsigned int index;
    unsigned int total;
    
    total = row * col;
    index = 0;
    while (index < total ) {
        if (a->lines[0][index] != b->lines[0][index]) return 0;
        index++;
    }
    return (1);
}

t_matrix* matrix_mult_chain(int num_args, ...) {
    va_list       ap;
    t_matrix*     m;
    t_coliseu*    coliseu;
    int  i;

    va_start(ap, num_args);

    i          = 0;
    coliseu    = va_arg(ap, t_coliseu*);
    m          = va_arg(ap, t_matrix*);
    num_args  -= 2;

    while ( i < num_args  ) {
        m = matrix_mult(m, va_arg(ap, t_matrix*), coliseu);
        i++;
    }

    va_end(ap);

    return(m);
}

t_matrix* matrix_mult(t_matrix* a, t_matrix* b, t_coliseu* coliseu) {
    t_matrix* result;
    unsigned int r;
    unsigned int c;
    unsigned int index;
    double       sum;

    if (a->cols != b->rows) {
        printf("numero de colunas da mat A %d tem que ser igual ao n° de linhas da mat B  %d\n", a->cols, b->rows);
        return (NULL);
    }
    sum = 0.0; r = 0; c = 0; index = 0;
    result = matrix_new(a->rows, b->cols, coliseu);

    while (r < b->rows) {
        while (c < a->cols) {
            sum   = 0.0;
            index = 0;
            while (index < a->cols) {
                sum += a->lines[r][index] * b->lines[index][c];
                index++;
            }
            result->lines[r][c] = sum;
            c++;
        }
        c = 0;
        r++;
    }
    return (result);
}


t_matrix* matrix_new(unsigned short int rows, unsigned short int cols, t_coliseu* coliseu) {
    unsigned int offset;
    t_matrix* m;

    offset = 1;
    m        =  new(1, sizeof(t_matrix), coliseu);
    
    if (!m) {
        ft_printf("%s\n", "Erro ao Alocar matriz");
        return (NULL);
    }
    m->cols  = cols;
    m->rows  = rows;
    m->lines = new(rows, sizeof(double*), coliseu);

    m->lines[0] = (double*) new(rows * cols, sizeof(double), coliseu);

    if (!m->lines[0]) {
        ft_printf("%s\n", "Erro ao Alocar matriz");
        ft_coliseu_rollback(coliseu->region, rows * sizeof(void*));
        return (NULL);
    }

    while(offset < rows) {
        m->lines[offset] = m->lines[0] + offset * cols;
        offset++;
    }
    return (m);
}

double matrix_get(unsigned short r, unsigned short c, t_matrix* m) {
    if (r > m->rows || c > m->cols) {
        ft_printf("warn: acessando memoria que não pertence a matriz\n");
        return 0.0;
    }
    return (m->lines[r][c]);
}

t_matrix* matrix_transpose(t_matrix *m, t_coliseu* coliseu)
{
    t_matrix* result;
    unsigned short r;
    unsigned short c;

    result = matrix_new(m->rows, m->cols, coliseu);
    if (!result)
        return (NULL);
    r = 0; c =  0;

    while (r < m->rows) {
        while (c < m->cols) {
            result->lines[c][r] = m->lines[r][c];
            c++;
        }
        c  = 0;
        r++;
    }
    return (result);
}

t_matrix* matrix_identy(unsigned short int rows, unsigned short int cols, t_coliseu* coliseu) {
    t_matrix* m;
    unsigned int r;
    
    if (rows != cols)
        return (NULL);

    r = 0;
    m = matrix_new(rows,  cols,  coliseu);

    while (r < rows) {
        m->lines[r][r] = 1;
        r++;
    }

    return(m);
}

t_matrix* matrix_submatrix(t_matrix *m, unsigned short int row, unsigned short int col, t_coliseu* coliseu) {
    t_matrix* result;
    unsigned short r;
    unsigned short c;
    unsigned short r1;
    unsigned short c1;
    
    if (row > m->rows || col > m->cols)
        return (NULL);
    r = 0; c = 0; r1 = 0; c1 = 0;
    result = matrix_new(m->rows - 1, m->cols- 1, coliseu);

    while (r < m->rows) {
        if (r != row) {
            while (c < m->cols) {
                if (c != col) {
                    result->lines[r1][c1] = m->lines[r][c];
                    c1++;
                }
                c++;
            }
            c1 = 0;
            r1++;
        }
        c = 0;
        r++;
    }
    return (result);
}

t_matrix *matrix_reverse(t_matrix *m, t_coliseu* coliseu)
{
    t_matrix* reverse;

    unsigned short int r;
    unsigned short int c;
    double determinant;

    r = 0; c = 0;

    if (!matrix_reversible(m))
        return (NULL);

    determinant = matrix_determinant(m);
    reverse     = matrix_new(m->rows, m->cols, coliseu);

    while (c < m->cols) {
        while (r < m->rows) {
            reverse->lines[c][r] = matrix_cofactor(m, r,  c) / determinant;
            r++;
        }
        r = 0;
        c++;
    }
    return (reverse);
}

double matrix22_determiant(t_matrix *m) {
    if (m->cols != 2 || m->rows != 2)
        return (0.0);
    return ((m->lines[0][0] * m->lines[1][1]) - (m->lines[0][1] * m->lines[1][0]));;
}


double matrix_determinant(t_matrix* m) {
    static t_coliseu local = { .door = NULL, .region = NULL, .size = ARENA_65KB };
    
    double         determinant = 0.0;
    unsigned short c;
    t_matrix*      sub;

    if (m->rows == 2 && m->cols == 2) 
        return (matrix22_determiant(m));
 
    c = 0;
    while(c < m->cols) { 
        sub = matrix_submatrix(m, 0, c, &local);
        if (c & 1)
            determinant += m->lines[0][c] * -matrix_determinant(sub);
        else 
           determinant += m->lines[0][c]  * matrix_determinant(sub); 
        c++;
    }
    ft_arena_destroy(&local);
    return (determinant);
}

double matrix_minor(t_matrix* m, unsigned short row, unsigned short col) {

    t_matrix* r;
    double    determinant;

    r           = matrix_submatrix(m, row, col, NULL);
    determinant = matrix_determinant(r);

    return (determinant);
}

double matrix_cofactor(t_matrix *a, unsigned short row, unsigned short col) {
    if ((row + 1 + col + 1) & 1)
        return (-matrix_minor(a, row, col));
    return (matrix_minor(a, row, col));
}

unsigned char matrix_reversible(t_matrix *m) {
    if (matrix_determinant(m)) 
        return (1);
    return (0);
}