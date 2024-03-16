/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:37 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/16 18:20:08 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	size_t	i;
	char	*sub;
	char	*str;
	int		l;

	i = 0;
	l = ft_strlen(s);
	if (l <= len + (int)start)
		sub = malloc((l - start + 1) * sizeof(char));
	else
		sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	str = (char *)s;
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	ft_strlcpy(sub, (str + start), len + 1);
	return (sub);
}
