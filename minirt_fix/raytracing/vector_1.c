/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:10:33 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:10:54 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vector	reflect(t_vector d, t_vector normal)
{
	return (normalized(sub_vec(d,
				scale_vec(normal, 2 * dot_product(d, normal)))));
}

t_vector	get_rotation_vector(t_vector normal)
{
	float	x;
	float	y;
	float	z;

	x = atan2(normal.y, -normal.z);
	y = atan2(-normal.x, sqrtf(square(normal.y) + square(normal.z)));
	z = atan2(normal.x, normal.y);
	return (new_vec(x, y, z));
}
