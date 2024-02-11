#include "../../includes/minit_rt.h"

//t_vector *at(float t, t_ray *ray) {
//    return NULL;
//}

static void ray_free(void *ray) {
    free((t_ray *) ray);
}

t_ray* ray_new(t_vector* center, t_vector* direction) {
    t_ray *ray;

    ray = (t_ray *) new(1, sizeof(t_ray),  ray_free, LONG);

    if (!ray)
        ft_printf("Memoria insuficiente, code: %d - ray_utils.c:17", MEM_ERROR);
    ray->direction = direction;
    ray->origin    = center;
    return (ray);
}

t_vector* ray_color(t_ray  *ray) {
   
    t_vector *a = vector_new(1.0, 1.0, 1.0);
    t_vector *b = vector_new(0.5, 0.7, 1.0);

    float factor = (ray->direction->y + 1.0) * 0.5;
    return (vsum(vmultf(a, (1 - factor)), vmultf(b, factor)));
}
