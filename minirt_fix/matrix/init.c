/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:08:00 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 20:08:48 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fill_mt(t_matrix *mt, float *values)
{
	int	k;
	int	i;
	int	j;

	k = 0;
	i = 0;
	while (i < mt->rows)
	{
		j = 0;
		while (j < mt->cols)
		{
			mt->matrix[i][j] = values[k++];
			j++;
		}
		i++;
	}
}

float	*create_cols(int c, t_coliseu *coliseu)
{
	int		i;
	float	*new_col;

	i = 0;
	new_col = ft_smart_calloc(c, sizeof(float), coliseu);
	while (i < c)
		new_col[i++] = .0;
	return (new_col);
}

t_matrix	*create_matrix(int rows, int cols, t_coliseu *coliseu)
{
	t_matrix	*new_mt;
	int			i;
	float		**mt;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	new_mt = ft_smart_calloc(1, sizeof(t_matrix), coliseu);
	i = 0;
	new_mt->rows = rows;
	new_mt->cols = cols;
	mt = ft_smart_calloc(rows, sizeof(float *), coliseu);
	while (i < rows)
		mt[i++] = create_cols(cols, coliseu);
	new_mt->matrix = mt;
	return (new_mt);
}
