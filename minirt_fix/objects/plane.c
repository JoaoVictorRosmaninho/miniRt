/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:06:56 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:06:57 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	test_plane(t_ray *ray, t_info *info)
{
	float		d;
	float		denom;
	float		t;
	t_vector	axis;

	axis = normalized(info->e->d_normal);
	d = -dot_product(axis, info->e->translation);
	denom = dot_product(axis, ray->direction);
	if (fabs(denom) < EPSILON)
		return (0);
	t = (-d - dot_product(ray->point1, axis)) / denom;
	if (t < EPSILON)
		return (0);
	info->normal = axis;
	if (dot_product(info->normal, ray->direction) > 0)
		info->normal = scale_vec(info->normal, -1);
	info->hitpoint = add_vec(ray->point1, scale_vec(ray->direction, t));
	return (1);
}
