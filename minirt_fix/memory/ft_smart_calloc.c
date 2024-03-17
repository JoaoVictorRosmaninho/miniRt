/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:00:41 by leoferre          #+#    #+#             */
/*   Updated: 2024/03/17 14:42:25 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	*ft_smart_calloc(size_t count, size_t size, t_coliseu* coliseu)
{
	void	*p;

	if (!coliseu)
		coliseu = ft_coliseu_manager(TAKE);
	p =  ft_arena_alloc(count * size, coliseu);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}