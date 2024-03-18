/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_align_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:20:04 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 20:03:25 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arena.h"

size_t	ft_arena_normalizer(size_t chunk)
{
	chunk--;
	chunk |= chunk >> 1;
	chunk |= chunk >> 2;
	chunk |= chunk >> 4;
	chunk |= chunk >> 8;
	chunk |= chunk >> 16;
	return (++chunk);
}

size_t	ft_align(size_t request_size)
{
	return (((request_size) + ((ARENA_ALIGN_SIZE) - 1))
		& ~((ARENA_ALIGN_SIZE) - 1));
}
