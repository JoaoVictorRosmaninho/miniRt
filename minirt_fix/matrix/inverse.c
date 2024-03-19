/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:07:33 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 20:07:41 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	determinant(t_matrix *mt)
{
	float	d;
	int		column_index;

	column_index = 0;
	d = 0;
	if (mt->cols != mt->rows)
		return (0);
	if (mt->cols == 2 || mt->rows == 2)
		d = (mt->matrix[0][0] * mt->matrix[1][1]) - (mt->matrix[0][1]
				* mt->matrix[1][0]);
	else
	{
		while (column_index < mt->cols)
		{
			d += mt->matrix[0][column_index] * cofactor(mt, 0, column_index);
			column_index++;
		}
	}
	return (d);
}

float	cofactor(t_matrix *mt, int row, int column)
{
	int	sign;

	sign = 1;
	if ((row + column) % 2 != 0)
		sign = -1;
	return (sign * minor(mt, row, column));
}

t_matrix	*inverse(t_matrix *mt, t_coliseu *coliseu)
{
	t_matrix	*m_inverse;
	int			row_index;
	int			col_index;
	float		c;
	float		dt;

	dt = determinant(mt);
	if (dt == 0)
		return (NULL);
	m_inverse = create_matrix(mt->rows, mt->cols, coliseu);
	row_index = 0;
	while (row_index < mt->rows)
	{
		col_index = 0;
		while (col_index < mt->cols)
		{
			c = cofactor(mt, row_index, col_index);
			m_inverse->matrix[col_index][row_index] = (c / dt);
			col_index++;
		}
		row_index++;
	}
	return (m_inverse);
}
