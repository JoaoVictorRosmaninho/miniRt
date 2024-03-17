#include "../../includes/minit_rt.h"

t_matrix* rotation_x(double pi_rad, t_coliseu* coliseu)
{
    t_matrix* rotation_matrix;


    rotation_matrix = matrix_identy(4,4, coliseu);

    rotation_matrix->lines[1][1] = cos(pi_rad);
    rotation_matrix->lines[1][2] = -sin(pi_rad);
    rotation_matrix->lines[2][1] = sin(pi_rad);
    rotation_matrix->lines[2][2] = cos(pi_rad);

    return(rotation_matrix);
} 

t_matrix* rotation_y(double pi_rad, t_coliseu* coliseu)
{
    t_matrix* rotation_matrix;


    rotation_matrix = matrix_identy(4,4, coliseu);

    rotation_matrix->lines[0][0] = cos(pi_rad);
    rotation_matrix->lines[0][2] = sin(pi_rad);
    rotation_matrix->lines[2][0] = -sin(pi_rad);
    rotation_matrix->lines[2][2] = cos(pi_rad);

    return(rotation_matrix);
    
}

t_matrix* rotation_z(double pi_rad, t_coliseu* coliseu)
{
    t_matrix* rotation_matrix;


    rotation_matrix = matrix_identy(4,4, coliseu);

    rotation_matrix->lines[0][0] = cos(pi_rad);
    rotation_matrix->lines[0][1] = -sin(pi_rad);
    rotation_matrix->lines[1][0] = sin(pi_rad);
    rotation_matrix->lines[1][1] = cos(pi_rad);

    return(rotation_matrix);
    
}


t_matrix* shearing(double* values, t_coliseu*  coliseu) {

    t_matrix* s;

    s = matrix_identy(4,4, coliseu);
    s->lines[0][Y] = values[0]; // X_Y
    s->lines[0][Z] = values[1]; // X_Z
    s->lines[1][X] = values[2]; // Y_X
    s->lines[1][Z] = values[3]; // Y_Z
    s->lines[2][X] = values[4]; // Z_X
    s->lines[2][Y] = values[5]; // Z_Y

    return (s);
}