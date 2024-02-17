#include "../../includes/sphere.h"


unsigned char hit_sphere(t_position *center, float radius, t_ray *ray) {

    t_vector *orientation = vsub(ray->origin, center);

    float a     = dot(ray->direction, ray->direction);
    float b     = 2.0 * dot(orientation, ray->direction);
    float c     = dot(orientation, orientation) - radius*radius;
    float delta = b*b - 4*a*c;

    return (delta >= 0);    
}


