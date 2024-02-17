#include "../../includes/minit_rt.h"

extern t_memory* memory;

static void ray_free(void *ray) {
    free((t_ray *) ray);
}


t_ray* ray_new(t_vector* center, t_vector* direction) {
    t_ray *ray;

    ray = (t_ray *) new(1, sizeof(t_ray),  ray_free, memory->where_write);

    ray->direction = direction;
    ray->origin    = center;
    return (ray);
}

//  function to implement a simple gradient
t_vector* ray_color(t_ray  *ray) {
    t_vector* ref = vector_new(0,0,-1);

    if (hit_sphere(ref, 0.5, ray)) {
        return vector_new(1,0,0);
    }
    t_vector *a = vector_new(1.0, 1.0, 1.0);
    t_vector *b = vector_new(0.5, 0.7, 1.0);

    float factor = (ray->direction->y + 1.0) * 0.5;
    return (vsum(vmultf(a, (1 - factor)), vmultf(b, factor)));
}
