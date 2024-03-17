#ifndef MINIRT_H
#define MINIRT_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>


#include "../libs/libft/includes/libft.h"


typedef struct {
    int height;
    int projected_height;
    int width;
    int file;
    float ratio;
    float viewport_width;
    float focal_center;
} t_context;

typedef enum {
    CMD_ERROR,
    MEM_ERROR,
    NO_ERROR
} e_errors;



#include "./memory.h"
#include "./matrix.h"
#include "./vector.h"
#include "./sphere.h"
#include "./transform.h"
#include "./rotations.h"
#include "./point.h"

typedef t_vector t_point;
typedef t_vector t_color;
typedef struct s_ray {     t_vector  *origin;     t_vector  *direction; } t_ray ;
//ray 

t_ray*    ray_new(t_vector* center, t_vector* direction);

// vector operations

t_vector* ray_color(t_ray  *ray);


#endif