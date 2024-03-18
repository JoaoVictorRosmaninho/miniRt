/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:11:10 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 21:50:15 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	test_intersection(t_ray *ray, t_object *objects, t_info *info)
{
	t_norm2	norm;

	ft_bzero(&norm, sizeof(t_norm2));
	norm.intfound = 0;
	norm.validint = 0;
	norm.mindist = 10e6;
	norm.i = -1;
	while (objects[++norm.i].gtfm)
	{
		norm.test.e = &objects[norm.i];
		norm.validint = objects[norm.i].hit(ray, &norm.test);
		if (norm.validint == 1)
		{
			norm.intfound = 1;
			norm.dist = length(sub_vec(norm.test.hitpoint, ray->point1));
			if (norm.dist < norm.mindist)
			{
				norm.mindist = norm.dist;
				info->e = norm.test.e;
				info->hitpoint = norm.test.hitpoint;
				info->normal = norm.test.normal;
			}
		}
	}
	return (norm.intfound);
}
