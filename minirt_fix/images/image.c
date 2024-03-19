/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:04:38 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 20:05:08 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	**new_channel(void)
{
	float	**channel;
	int		i;
	int		j;

	channel = ft_smart_calloc(HEIGHT, sizeof(float *), NULL);
	i = 0;
	while (i < HEIGHT)
	{
		channel[i] = ft_smart_calloc(WIDTH, sizeof(float), NULL);
		j = 0;
		while (j < WIDTH)
			channel[i][j++] = 0.0f;
		i++;
	}
	return (channel);
}

t_image	*new_image(void)
{
	t_image	*image;

	image = ft_smart_calloc(1, sizeof(t_image), NULL);
	image->red = new_channel();
	image->green = new_channel();
	image->blue = new_channel();
	return (image);
}

void	delete_image(t_image *image)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(image->red[i]);
		free(image->green[i]);
		free(image->blue[i]);
		i++;
	}
	free(image->red);
	free(image->green);
	free(image->blue);
	free(image);
}

void	set_pixel(t_image *image, int x, int y, t_vector color)
{
	image->red[y][x] = color.x;
	image->green[y][x] = color.y;
	image->blue[y][x] = color.z;
}

t_data	*new_mlx_img(t_vars *vars)
{
	t_data	*mlx_img;

	mlx_img = ft_smart_calloc(1, sizeof(t_data), NULL);
	mlx_img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	mlx_img->addr = mlx_get_data_addr(mlx_img->img, &mlx_img->bits_per_pixel,
			&mlx_img->line_length, &mlx_img->endian);
	return (mlx_img);
}
