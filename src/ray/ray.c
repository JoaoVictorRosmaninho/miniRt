#include "../../includes/minit_rt.h"

t_vector *at(float t, t_ray *ray) {
    return NULL;
}


t_ray* ft_build_ray(t_vector* center, t_vector* direction) {
    t_ray *ray;

    ray = ft_calloc(1, sizeof(ray));
    if (!ray) new_error("Memoria insuficiente - ray_utils.c:17", MEM_ERROR);
    ray->direction = direction;
    ray->origin    = center;
    return (ray);
}

t_vector* ray_direction(t_ray  *ray) {
   
    t_vector *a = vector_new(1.0, 1.0, 1.0);
    t_vector *b = vector_new(0.5, 0.7, 1.0);

    float factor = (ray->direction->y + 1.0) * 0.5;

    return (vsum(vmultf(a, (1 - factor)), vmultf(b, factor)));
}