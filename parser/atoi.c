/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:53:52 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/11 18:56:15 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	atoi_int(char *str, int *i, int *sign, float res)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	res = 0;
	while (str && isdigit(str[*i]))
	{
		res = 10 * res + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

float	atoi_float(char *str, int *i, float res)
{
	int	pres;

	pres = 10;
	while (str && isdigit(str[*i]))
	{
		res = res + (float)(str[*i] - '0') / pres;
		(*i)++;
		pres *= 10;
	}
	return (res);
}