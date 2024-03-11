/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:27:36 by leoferre          #+#    #+#             */
/*   Updated: 2022/07/09 14:44:32 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*lines;
	char		*acc;
	static char	*buffer;

	if (BUFFER_SIZE < 0 || fd < 0 || fd > 255)
		return (NULL);
	acc = notline (fd, buffer);
	lines = putline (acc);
	buffer = cut (acc);
	if (lines != acc)
		free(acc);
	if (ft_strlen(lines) == 0 && buffer == NULL)
	{
		free(lines);
		free(buffer);
		return (NULL);
	}
	return (lines);
}

char	*notline(int fd, char *buffer)
{
	char	*temp;
	char	*tempbuf;
	int		i;

	if (!buffer)
		buffer = ft_strdup("");
	i = 1;
	tempbuf = malloc((BUFFER_SIZE + 1));
	ft_memset(tempbuf, 0, (BUFFER_SIZE + 1));
	while (!ft_strchr(tempbuf, '\n') && i != 0)
	{
		i = read(fd, tempbuf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			free(tempbuf);
			return (NULL);
		}
		tempbuf[i] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, tempbuf);
		free(temp);
	}
	free(tempbuf);
	return (buffer);
}

char	*putline(char *lines)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strchr(lines, '\n');
	if (temp == NULL)
		i = (int)ft_strlen(lines);
	else
	{
		while (lines[i])
		{
			if (lines[i] == '\n')
				break ;
			i++;
		}
	}
	if (ft_strchr(lines, '\n'))
	{
		temp = (char *)malloc(sizeof(char) * (i + 2));
		temp = ft_memcpy(temp, lines, (i + 1));
		temp[i + 1] = '\0';
		return (temp);
	}
	else
		return (lines);
}

char	*cut(char *buffer)
{
	char	*tempbuffer;
	char	*temp;

	if (!buffer)
		return (NULL);
	temp = ft_strchr(buffer, '\n');
	if (temp == NULL)
		return (NULL);
	tempbuffer = malloc(sizeof(char) * (ft_strlen(temp + 1) + 1));
	tempbuffer = ft_memcpy(tempbuffer, (temp + 1), ft_strlen(temp + 1));
	tempbuffer[ft_strlen(temp + 1)] = '\0';
	if (*buffer == '\0')
		return (NULL);
	return (tempbuffer);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned char)c == '\0')
		return ((char *)(s + len_s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
