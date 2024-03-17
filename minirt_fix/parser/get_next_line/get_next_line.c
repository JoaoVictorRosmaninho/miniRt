/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:27:36 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/16 18:48:35 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_setlines(char *str);
char	*ft_savenextline(char *str);

char	*get_next_line(int fd)
{
	static char	*nextone;
	char		s[BUFFER_SIZE + 1];
	char		*line;
	int			n;

	if ((fd < 0 || fd > 10240) || BUFFER_SIZE <= 0)
		return (0);
	n = 1;
	while (!(ft_strchr1(nextone, '\n')) && n != 0)
	{
		n = read(fd, s, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		s[n] = '\0';
		nextone = ft_strjoin1(nextone, s);
	}
	line = ft_setlines(nextone);
	nextone = ft_savenextline(nextone);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_setlines(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_savenextline(char *str)
{
	char	*alloc;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	alloc = malloc((ft_strlen1(str) - i) * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		alloc[j++] = str[i++];
	alloc[j] = '\0';
	free(str);
	return (alloc);
}