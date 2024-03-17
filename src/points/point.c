#include "../../includes/minit_rt.h"


t_point2* point_new(double  x,  double y, double z, t_coliseu* coliseu) {
    t_point2* point;

    point = matrix_new(4,1, coliseu);

    point->lines[X][0] = x;
    point->lines[Y][0] = y;
    point->lines[Z][0] = z;


    return (point);
}