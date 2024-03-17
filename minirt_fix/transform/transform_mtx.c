#include "../main.h"

t_vector	apply_transform_vector(t_vector *input,
	t_matrix **gtfm, int dirflag)
{
	t_vector	output;
	t_matrix	*tempdata;
	t_matrix	*result;
	t_coliseu	local;
	float		*values;

	ft_coliseu_initialize(&local, ARENA_32KB, 1);
	tempdata = create_matrix(4, 1, &local);
	values = (float []){input->x, input->y, input->z, 1.0f};
	fill_mt(tempdata, values);
	if (dirflag)
		result = mt_multiplication(gtfm[0], tempdata, &local);
	else
		result = mt_multiplication(gtfm[1], tempdata, &local);
	if (!result)
		return ((t_vector){0, 0, 0});
	output = new_vec(result->matrix[0][0],
			result->matrix[1][0], result->matrix[2][0]);
	ft_arena_destroy(&local);
	return (output);
}

t_ray	apply_transform(t_ray *ray, t_matrix **gtfm, int dirflag)
{
	t_ray	new_ray;

	new_ray.point1 = apply_transform_vector(&ray->point1, gtfm, dirflag);
	new_ray.point2 = apply_transform_vector(&ray->point2, gtfm, dirflag);
	new_ray.direction = sub_vec(new_ray.point2, new_ray.point1);
	return (new_ray);
}

t_matrix	**set_transform(t_vector t, t_vector r, t_vector s)
{
	t_matrix	**transform;
	t_matrix	*forward;
	t_matrix	*backward;
	t_coliseu	local[2];


	ft_coliseu_initialize(local, ARENA_4KB, 2);

	transform = ft_smart_calloc(2,  sizeof(t_matrix *), NULL);
	forward  = safe_matrix_multy(translation_matrix(&t, &local[0]), rotation_matrix_x(r.x, &local[0]), local);
	forward  = safe_matrix_multy(forward, rotation_matrix_y(r.y, &local[0]), local);
	forward  = safe_matrix_multy(forward, rotation_matrix_z(r.z, &local[0]), local);
	forward  = safe_matrix_multy(forward, scaling_matrix(&s, &local[0]), NULL);
	backward = inverse(forward, NULL);
	transform[0] = forward;
	transform[1] = backward;
	ft_arena_destroy(local);
	ft_arena_destroy(local +  1);
	return (transform);
}
