/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:20:04 by jv                #+#    #+#             */
/*   Updated: 2024/03/17 19:07:25 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arena.h"

void	ft_arena_free(t_coliseu *coliseu)
{
    t_arena *arena;

				if (!coliseu) {
								printf("coliseu inválido\n");
								return ;
				}
				arena = coliseu->door;
				if (!arena) {
				}
				while (arena) {
								arena->begin = (char*) arena + sizeof(t_arena);
								arena = arena->next;
				}
				coliseu->region = coliseu->door;
}

void    ft_coliseu_rollback(t_arena *region, size_t rollback) {
				if (!region) {
								printf("endereço de arena inválido\n");
								return ;
				}
				if ((region->begin - rollback) < (region->end + sizeof(void*) - region->chunk)) {
								printf("endereço de retorno inválido\n");
								return ;
				}
				region->begin -= rollback;
}   

void ft_arena_destroy(t_coliseu *coliseu)
{
				t_arena* arena;
				t_arena* _arena;

				arena = coliseu->door;
				while (arena) {
					_arena = arena;
						arena = arena->next;
					free(_arena);
				} 
				coliseu->door   = NULL;
				coliseu->region = NULL;
}


void ft_coliseu_initialize(t_coliseu* group, size_t size_of_coliseu, size_t length) {

				size_t index;

				index = 0;

				while (index < length) {
								group[index].region = NULL;
								group[index].door   = NULL;
								group[index].size   = size_of_coliseu;
								index++;
				}
}

void* ft_arena_alloc(size_t chunk, t_coliseu *coliseu) {
				
				void* memory;
				long real_chunk;

				if (!coliseu || !chunk)
				{
								printf("Coliseu inválido ou tamanho invalido\n");
								return (NULL);
				}
				real_chunk = ft_align(chunk);
				if (!coliseu->region)
				{
								if (!coliseu->size)  {
												printf("Coliseu inválido\n");
												return (NULL);
								}
								ft_coliseu_create(coliseu);

								memory = ft_find_or_create_arena(coliseu, chunk);
				} else {
								memory = coliseu->region->begin;
								if ((real_chunk + sizeof(t_arena)) > PTRDIFF_MAX) {
												printf("Impossivel  alocar, overflow condition\n");
												return (NULL);
								}
								// Marcando como usada
								if (coliseu->region->begin + real_chunk > coliseu->region->end) {
												// Não tem meomoria suficiente
												// alocar uma nova
												memory = ft_find_or_create_arena(coliseu, real_chunk);
								}
				}
				coliseu->region->begin += real_chunk;
				return (memory);
}


t_coliseu* ft_coliseu_manager(enum e_types action)