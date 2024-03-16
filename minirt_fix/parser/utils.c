/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:54:12 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/15 20:18:39 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	whitespaces(char str)
{
	while (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	return (0);
}

int	skip_space(char *str, int i)
{
	while (str && whitespaces(str[i]))
		i++;
	return (i);
}

void	check_numbers(float num, float min, float max)
{
	if (num < min || num > max)
	{
		printf("Parsing Error : unexpected number\n");
		exit(EXIT_FAILURE);
	}
}

int	check_extention(char *str)
{
	if (!(ft_strchr(str, '.')))
	{
		printf("Parsing Error : missing dot\n");
		return (1);
	}
	if (ft_strncmp(ft_strchr(str, '.'), ".rt", 4) != 0)
	{
		printf("Parsing Error : invalid extension\n");
		return (1);
	}
	return (0);
}
