#include "../../includes/matrix.h"

extern t_memory g_memory;


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

t_matrix* matrix_mult(t_matrix* a, t_matrix* b) {
    t_matrix* result;
    unsigned int r;
    unsigned int c;
    unsigned int index;
    double       sum;

    if (a->cols != b->rows) {
        ft_printf("%s\n", "numero de colunas da mat A tem que ser igual ao n° de linhas da mat B");
        return (NULL);
    }
    sum = 0.0; r = 0; c = 0; index = 0;
    result = matrix_new(a->rows, b->cols);

    while (r < a->rows) {
        while (c < b->cols) {
            sum   = 0.0;
            index = 0;
            while (index < a->rows) {
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


t_matrix* matrix_new(unsigned short int rows, unsigned short int cols) {
    unsigned int offset;
    t_matrix* m;

    offset = 1;
    m        =  new(1, sizeof(t_matrix), g_memory.coliseu);
    
    if (!m) {
        ft_printf("%s\n", "Erro ao Alocar matriz");
        return (NULL);
    }
    m->cols  = cols;
    m->rows  = rows;
    m->lines = new(rows, sizeof(double*), g_memory.coliseu);

    m->lines[0] = (double*) new(rows * cols, sizeof(double), g_memory.coliseu);

    if (!m->lines[0]) {
        ft_printf("%s\n", "Erro ao Alocar matriz");
        ft_coliseu_rollback(g_memory.memory[g_memory.coliseu].region, rows * sizeof(void*));
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

t_matrix* matrix_transpose(t_matrix *m)
{
    t_matrix* result;
    unsigned short r;
    unsigned short c;

    result = matrix_new(m->rows, m->cols);
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

t_matrix* matrix_submatrix(t_matrix *m, unsigned short int row, unsigned short int col) {
    t_matrix* result;
    unsigned short r;
    unsigned short c;
    unsigned short r1;
    unsigned short c1;
    
    if (row > m->rows || col > m->cols)
        return (NULL);
    r = 0; c = 0; r1 = 0; c1 = 0;
    result = matrix_new(m->rows - 1, m->cols- 1);

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

double matrix22_determiant(t_matrix *m) {
    if (m->cols != 2 || m->rows != 2)
        return (0.0);
    return(m->lines[0][0] * m->lines[1][1] - m->lines[0][1] * m->lines[1][0]);
    }

double matrix_determinant(t_matrix* m) {
    double det;
    unsigned short c;
    
    if (m->rows < 3 && m->cols < 3)
        return (matrix22_determiant(m));
    det  = 0.0;
    c    = 0;

    while ( c < m->cols ) {
        det += m->lines[0][c] * matrix_cofactor(m, 0, c);
        c++;
    }
    return (det);
}

double matrix_minor(t_matrix* m, unsigned short row, unsigned short col) {

    t_matrix* r;
    double determinant;

    r           = matrix_submatrix(m, row, col);
    determinant = matrix22_determiant(r);

    // TA ZOADO, tenho que melhorar a interface de memoria,  caso uma função  queira criar um  coliseu prorio, no  problem
    ft_coliseu_rollback(g_memory.memory[g_memory.coliseu].region, r->rows * r->cols * sizeof(double) + sizeof(double*));
    return (determinant);
}

double matrix_cofactor(t_matrix *a, unsigned short row, unsigned short col) {
    if ((row + col) & 1)
        return (-matrix_minor(a, row, col));
    return (matrix_minor(a, row, col));
}

unsigned char matrix_reversible(t_matrix *m) {
    if (matrix_determinant(m)) 
        return (1);
    return (0);
}