/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:53:49 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/11 18:55:57 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_sphere(t_vars *var, char *line, int i)
{
	t_object	obj;

	i += 2;
	obj.type = SPHERE;
	obj.translation = parse_vector(line, &i);
	obj.radius = parse_number(line, &i) / 2;
	obj.base_color = parse_vector(line, &i);
	check_numbers(obj.base_color.x, 0, 255);
	check_numbers(obj.base_color.y, 0, 255);
	check_numbers(obj.base_color.z, 0, 255);
	obj.base_color = scale_vec(obj.base_color, 1.0f / 255.0f);
	if (line[i])
	{
		printf("Error: unexpected %c\n", line[i]);
		exit(EXIT_FAILURE);
	}
	obj.has_material = 0;
	obj.shininess = 20;
	obj.reflectivity = 0.75;
	obj.rotation = (t_vector){0, 0, 0};
	obj.scale = (t_vector){obj.radius, obj.radius, obj.radius};
	obj.gtfm = set_transform(obj.translation, obj.rotation, obj.scale);
	obj.hit = test_sphere;
	add_object(var, obj);
	free (line);
}

void	check_plane(t_vars *var, char *line, int i)
{
	t_object	obj;

	i += 2;
	obj.type = PLANE;
	obj.translation = parse_vector(line, &i);
	obj.d_normal = parse_vector(line, &i);
	check_numbers(obj.d_normal.x, -1.0, 1.0);
	check_numbers(obj.d_normal.y, -1.0, 1.0);
	check_numbers(obj.d_normal.z, -1.0, 1.0);
	obj.base_color = parse_vector(line, &i);
	check_numbers(obj.base_color.x, 0, 255);
	check_numbers(obj.base_color.y, 0, 255);
	check_numbers(obj.base_color.z, 0, 255);
	obj.base_color = scale_vec(obj.base_color, 1.0f / 255.0f);
	if (line[i])
	{
		printf("Error: unexpected %c\n", line[i]);
		exit(EXIT_FAILURE);
	}
	obj.has_material = 0;
	obj.shininess = 5;
	obj.reflectivity = 0.5;
	obj.hit = test_plane;
	add_object(var, obj);
	free(line);
}

void	check_cy_continue(t_object *obj)
{
	obj->has_material = 0;
	obj->shininess = 10;
	obj->reflectivity = 0.75;
	obj->rotation = get_rotation_vector(obj->d_normal);
	obj->scale = (t_vector){obj->radius, obj->radius, obj->height};
	obj->gtfm = set_transform(obj->translation, obj->rotation, obj->scale);
	obj->hit = test_cylinder;
}

void	check_cylinder(t_vars *var, char *line, int i)
{
	t_object	obj;

	i += 2;
	obj.type = CYLINDER;
	obj.translation = parse_vector(line, &i);
	obj.d_normal = parse_vector(line, &i);
	check_numbers(obj.d_normal.x, -1.0, 1.0);
	check_numbers(obj.d_normal.y, -1.0, 1.0);
	check_numbers(obj.d_normal.z, -1.0, 1.0);
	obj.radius = parse_number(line, &i) / 2;
	obj.height = parse_number(line, &i);
	obj.base_color = parse_vector(line, &i);
	check_numbers(obj.base_color.x, 0, 255);
	check_numbers(obj.base_color.y, 0, 255);
	check_numbers(obj.base_color.z, 0, 255);
	obj.base_color = scale_vec(obj.base_color, 1.0f / 255.0f);
	if (line[i])
	{
		printf("Error: unexpected %c\n", line[i]);
		exit(EXIT_FAILURE);
	}
	check_cy_continue(&obj);
	add_object(var, obj);
	free(line);
}
