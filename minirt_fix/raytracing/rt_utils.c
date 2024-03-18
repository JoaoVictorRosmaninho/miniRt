/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:11:40 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 21:58:23 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	rand_pcg(unsigned int *rng_state)
{
	unsigned int	state;
	unsigned int	word;

	state = *rng_state;
	*rng_state = state * 747796405u + 2891336453u;
	word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return ((word >> 22u) ^ word);
}

float	random_float(unsigned int *rng_state, float min, float max)
{
	return (min + (rand_pcg(rng_state) * (1.0 / UINT_MAX)
		) * (max - min));
}

void	initialize_raytrace(t_vars *vars, t_norm1 *norm)
{
	norm->xfact = 1.0 / ((float)(WIDTH) / 2.0);
	norm->yfact = 1.0 / ((float)(HEIGHT) / 2.0);
	vars->frames++;
	vars->rng_state = vars->frames;
	norm->y = -1;
	norm->intfound = 0;
}

void	process_pixel(t_vars *vars, t_norm1 *norm)
{
	norm->xoff = random_float(&vars->rng_state, -0.5, 0.5);
	norm->yoff = random_float(&vars->rng_state, -0.5, 0.5);
	norm->normx = ((float)(norm->x + norm->xoff) * norm->xfact) - 1.0;
	norm->normy = ((float)(norm->y + norm->yoff) * norm->yfact) - 1.0;
	norm->ray = generate_ray(norm->normx, norm->normy, &vars->camera);
	norm->intfound = test_intersection(&norm->ray, vars->objects, &norm->info);
	if (norm->intfound)
	{
		norm->color = compute_color(vars, &norm->info, &norm->ray);
		vars->buffer_img[norm->y * WIDTH + norm->x]
			= add_vec(vars->buffer_img[norm->y * WIDTH + norm->x], norm->color);
		norm->color = scale_vec(vars->buffer_img[
				norm->y * WIDTH + norm->x], 1.0f / vars->frames);
		set_pixel(vars->image, norm->x, norm->y, norm->color);
	}
}

void	raytrace(t_vars *vars)
{
	t_norm1	norm;

	ft_bzero(&norm, sizeof(t_norm1));
	initialize_raytrace(vars, &norm);
	while (++norm.y < HEIGHT)
	{
		norm.x = -1;
		while (++norm.x < WIDTH)
			process_pixel(vars, &norm);
	}
}
