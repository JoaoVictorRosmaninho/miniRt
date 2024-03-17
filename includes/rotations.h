#ifndef ROTATION_H
# define ROTATION_H

typedef enum {
    X_Y,
    X_Z,
    Y_X,
    Y_Z,
    Z_X,
    Z_Y
} e_shearing_type;


t_matrix* rotation_x(double pi_rad, t_coliseu* coliseu);

t_matrix* rotation_y(double pi_rad, t_coliseu* coliseu);

t_matrix* rotation_z(double pi_rad, t_coliseu* coliseu);

t_matrix* shearing(double* values, t_coliseu*  coliseu);

#endif