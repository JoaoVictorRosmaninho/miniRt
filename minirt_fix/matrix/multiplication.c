/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:09:50 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:10:21 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_matrix	*mt_multiplication(t_matrix *mt1, t_matrix *mt2, t_coliseu *coliseu)
{
	t_matrix	*result;
	int			i;
	int			j;
	int			k;

	i = 0;
	if (!mt1 || !mt2 || mt1->cols != mt2->rows)
		return (NULL);
	result = create_matrix(mt1->rows, mt2->cols, coliseu);
	while (i < mt1->rows)
	{
		k = 0;
		while (k < mt2->cols)
		{
			j = 0;
			while (j < mt1->cols)
			{
				result->matrix[i][k] += (mt1->matrix[i][j] * mt2->matrix[j][k]);
				j++;
			}
			k++;
		}
		i++;
	}
	return (result);
}

t_matrix	*safe_matrix_multy(t_matrix *mt1, t_matrix *mt2, t_coliseu *coliseu)
{
	t_matrix	*result;

	if (!mt1 || !mt2)
		return (NULL);
	if (coliseu)
		result = mt_multiplication(mt1, mt2, coliseu + 1);
	else
		result = mt_multiplication(mt1, mt2, NULL);
	if (coliseu)
		ft_arena_free(coliseu);
	if (!result)
		printf("error in safe mt \n");
	return (result);
}
