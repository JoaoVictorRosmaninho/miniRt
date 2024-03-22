#include "../../includes/sphere.h"


unsigned char hit_sphere(t_vector *center, float radius, t_ray *ray) {
    t_coliseu local;

    ft_coliseu_initialize(&local, ARENA_512B, 1);

    t_vector *orientation = vsub(ray->origin, center, &local);

    float a     = vdot(ray->direction, ray->direction);
    float b     = 2.0 * vdot(orientation, ray->direction);
    float c     = vdot(orientation, orientation) - radius*radius;
    float delta = b*b - 4*a*c;

    ft_arena_destroy(&local);
    return (delta >= 0);    
}


