/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:08:48 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/16 18:33:39 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static char	**spiltwords(char const *s, char c, char **str, int count)
{
	int	i;
	int	j;
	int	len_words;
	int	start;

	i = 0;
	j = 0;
	len_words = 0;
	while (s[j] && i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
		{
			j++;
			len_words++;
		}
		str[i] = malloc((len_words + 1) * sizeof(char));
		ft_strlcpy(str[i], (s + start), len_words + 1);
		len_words = 0;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	count = count_words(s, c);
	if (!s)
		return (0);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (0);
	spiltwords(s, c, str, count);
	return (str);
}
