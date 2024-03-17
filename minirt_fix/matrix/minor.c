#include "../main.h"

void	copy_clmn(float *clm1, float *clm2, int column, int size)
{
	int	j;
	int	fci;

	j = 0;
	fci = 0;
	while (j < size)
	{
		if (j != column)
		{
			clm1[fci] = clm2[j];
			fci++;
		}
		j++;
	}
}

t_matrix	*submatrix(t_matrix *mt, int row, int column,  t_coliseu *coliseu)
{
	int			i;
	int			fri;
	t_matrix	*new_matrix;

	if (mt->rows <= 1 || mt->cols <= 1)
		return (mt);
	new_matrix = create_matrix(mt->rows - 1, mt->rows - 1,  coliseu);
	i = 0;
	fri = 0;
	while (i < mt->rows)
	{
		if (i == row)
		{
			i++;
			continue ;
		}
		copy_clmn(new_matrix->matrix[fri], mt->matrix[i], column, mt->cols);
		fri++;
		i++;
	}
	return (new_matrix);
}

float	minor(t_matrix *mt, int row, int column)
{
	t_matrix	*sub;
	float		m_determinant;
	t_coliseu	local;


	ft_coliseu_initialize(&local, ARENA_4KB, 1);
	sub = submatrix(mt, row, column, &local);
	m_determinant = determinant(sub);
	ft_arena_destroy(&local);
	return (m_determinant);
}
