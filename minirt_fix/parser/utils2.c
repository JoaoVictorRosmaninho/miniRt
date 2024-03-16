/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:54:15 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/15 20:18:44 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	indexation(char *line, int index)
{
	index = 0;
	if (line[0] == 'A')
		index = 0;
	else if (line[0] == 'C')
		index = 1;
	else if (line[0] == 'L')
		index = 2;
	return (index);
}

void	duplicate_error(char *line, int fd)
{
	printf("Parsing Error : duplicate\n");
	free(line);
	close(fd);
	exit(EXIT_FAILURE);
}

void	init_vars(t_elem *elem, char *str)
{
	elem->count[0] = 0;
	elem->count[1] = 0;
	elem->count[2] = 0;
	elem->fd = open(str, O_RDONLY);
}

void	missing_check(t_elem *elem)
{
	if (!(elem->count[0] == 1 && elem->count[1] == 1 && elem->count[2] == 1))
	{
		printf("Parsing Error : missing Element\n");
		exit(EXIT_FAILURE);
	}
}
