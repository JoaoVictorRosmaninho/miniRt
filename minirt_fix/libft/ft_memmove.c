/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:56:36 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/16 18:31:54 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (i <= len)
		{
			((unsigned char *)dst)[len - i] = ((unsigned char *)src)[len - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
