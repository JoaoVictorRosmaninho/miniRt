/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:20:26 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/16 18:33:09 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd ('-', fd);
		ln *= -1;
	}
	if (ln >= 10)
		ft_putnbr_fd ((ln / 10), fd);
	ft_putchar_fd ((ln % 10 + '0'), fd);
}
