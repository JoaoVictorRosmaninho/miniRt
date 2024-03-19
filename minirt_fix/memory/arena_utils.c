/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:20:04 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 19:43:59 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arena.h"

void	ft_arena_free(t_coliseu *coliseu)
{
	t_arena	*arena;

	if (!coliseu || !coliseu->door)
		return ;
	arena = coliseu->door;
	while (arena)
	{
		arena->begin = (char *) arena + sizeof(t_arena);
		arena = arena->next;
	}
	coliseu->region = coliseu->door;
}

void	ft_coliseu_rollback(t_arena *region, size_t rollback)
{
	if (!region)
		return ;
	if ((region->begin - rollback)
		< (region->end + sizeof(void*) - region->chunk))
		return ;
	region->begin -= rollback;
}

void	ft_arena_destroy(t_coliseu *coliseu)
{
	t_arena	*arena;
	t_arena	*_arena;

	arena = coliseu->door;
	while (arena)
	{
		_arena = arena;
		arena = arena->next;
		free(_arena);
	}
	coliseu->door = NULL;
	coliseu->region = NULL;
}

void	ft_coliseu_initialize(t_coliseu	*group,
	size_t size_of_coliseu, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		group[index].region = NULL;
		group[index].door = NULL;
		group[index].size = size_of_coliseu;
		ft_coliseu_create(&group[index]);
		index++;
	}
}
