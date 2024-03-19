/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:13:35 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 20:13:45 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	length2(t_vector a)
{
	return (square(a.x) + square(a.y) + square(a.z));
}

float	length(t_vector a)
{
	return (sqrtf(length2(a)));
}

t_vector	normalized(t_vector a)
{
	t_vector	new;
	float		l;

	new = new_vec(a.x, a.y, a.z);
	l = length(a);
	if (l)
		new = scale_vec(new, 1.0f / l);
	return (new);
}

float	dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	return (new);
}
