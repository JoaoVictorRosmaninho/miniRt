/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:07:13 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:07:17 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_to_indentity(t_matrix *mt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mt->rows)
	{
		j = 0;
		while (j < mt->cols)
		{
			if (i == j)
				mt->matrix[i][j] = 1.0f;
			else
				mt->matrix[i][j] = 0.0f;
			j++;
		}
		i++;
	}
}

void	print_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	if (!matrix)
		return ;
	i = 0;
	printf("[ \n");
	while (i < matrix->rows)
	{
		j = 0;
		printf("\t[ ");
		while (j < matrix->cols)
		{
			printf(" %f  %c", matrix->matrix[i][j], ' ');
			j++;
		}
		printf("],\n");
		i++;
	}
	printf("]\n");
}

void	delete_matrix(t_matrix *_this)
{
	int	row_index;

	row_index = 0;
	if (_this)
	{
		if (_this->matrix)
		{
			while (row_index < _this->rows)
			{
				if (_this->matrix[row_index])
					free(_this->matrix[row_index]);
				row_index++;
			}
			free(_this->matrix);
		}
		free(_this);
	}
}
