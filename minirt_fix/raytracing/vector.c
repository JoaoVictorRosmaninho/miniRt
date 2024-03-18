/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:11:25 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:11:29 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	square(float a)
{
	return (a * a);
}

t_vector	new_vec(float x, float y, float z)
{
	return ((t_vector){x, y, z});
}

t_vector	sub_vec(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	add_vec(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	scale_vec(t_vector a, float t)
{
	return ((t_vector){a.x * t, a.y * t, a.z * t});
}
