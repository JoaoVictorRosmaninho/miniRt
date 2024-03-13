#include "../../includes/translation.h"


t_translation* translation(double x, double y, double z, t_coliseu*  coliseu) {
    t_translation* t;

    t = matrix_identy(4,4, coliseu);
    t->lines[0][3] = x;
    t->lines[1][3] = y;
    t->lines[2][3] = z;

    return (t);
}

t_translation* transform(t_translation* translation, t_point* point) {
    return (NULL);
}