/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:25:06 by leoferre          #+#    #+#             */
/*   Updated: 2022/07/09 14:46:26 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char			*putline(char *lines);
char			*notline(int fd, char *buffer);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s);
char			*get_next_line(int fd);
char			*cut(char *buffer);
char			*ft_memcpy(void *dest, char *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

#endif
