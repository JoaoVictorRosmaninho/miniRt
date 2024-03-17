#include "../../includes/minit_rt.h"


t_matrix* translation_new(double x, double y, double z, t_coliseu*  coliseu) {
    t_matrix* t;

    t = matrix_identy(4,4, coliseu);
    t->lines[0][W] = x;
    t->lines[1][W] = y;
    t->lines[2][W] = z;

    return (t);
}

t_matrix* scale_new(double x, double y, double z, t_coliseu*  coliseu) {
    t_matrix* t;

    t = matrix_identy(4,4, coliseu);
    t->lines[0][0] = x;
    t->lines[1][1] = y;
    t->lines[2][2] = z;

    return (t);
}

t_point2* translation_transform(t_matrix* translation, t_point2* point, t_coliseu* coliseu) {
    
    t_matrix* result;

    result = matrix_new(1, 4, coliseu);

    result->lines[0][0] = translation->lines[0][3] + point->lines[0][0];
    result->lines[0][1] = translation->lines[1][3] + point->lines[0][1];
    result->lines[0][2] = translation->lines[2][3] + point->lines[0][2];

    return (result);
}
