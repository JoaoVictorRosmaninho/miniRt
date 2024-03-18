/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-paul <jde-paul@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:56:14 by jde-paul                #+#    #+#             */
/*   Updated: 2024/03/17 19:54:05 by jde-paul               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "../libft/libft.h"

# define ARENA_MIN_ALLOC_SIZE 8
# define ARENA_ALIGN_SIZE 8

# define ARENA_64B 64 // 64 bytes
# define ARENA_128B 128 // 128 bytes
# define ARENA_256B 256 // 256 bytes
# define ARENA_512B 512 // 512 bytes
# define ARENA_1KB 1024 // 1kb
# define ARENA_2KB 2056 // 2kb
# define ARENA_4KB 4096 //  4kb
# define ARENA_8KB 8192 // 8kb
# define ARENA_16KB 16384 // 16KB
# define ARENA_32KB 32768 // 32KB
# define ARENA_65KB 65536 // 65KB
# define ARENA_131KB 131072 // 130KB

# define NUMBER_OF_COLISEUS 20

enum e_types
{
	TAKE,
	GIVE_BACK
};

typedef struct s_arena
{
	struct s_arena	*next;
	size_t			chunk;
	char			*end;
	char			*begin;
}	t_arena;

typedef struct s_ctx_arena
{
	t_arena	*arena_prev;
	t_arena	*arena;
	long	avaliable;
	long	real_size;
}	t_ctx_arena;

typedef struct s_coliseu
{
	t_arena	*door;
	t_arena	*region;
	size_t	size;
}	t_coliseu;
// free arena
void		ft_arena_free(t_coliseu *coliseu);
// destroy_arena and free process memory
void		ft_arena_destroy(t_coliseu *coliseu);
// alloc memory from specific arena
void		*ft_arena_alloc(size_t chunk, t_coliseu *coliseu);
// create a coliseu
void		ft_coliseu_create(t_coliseu	*coliseu);

void		*ft_find_or_create_arena(t_coliseu *coliseu, size_t chunk);
// rollback a specific size
void		ft_coliseu_rollback(t_arena *region, size_t rollback);
// arena manager for better interface
t_coliseu	*ft_coliseu_manager(enum e_types action);
//  smart allocator, no leaks
void		*ft_smart_calloc(size_t count, size_t size, t_coliseu *coliseu);

void		ft_coliseu_initialize(t_coliseu *group, size_t size_of_coliseu,
				size_t length);

size_t		ft_arena_normalizer(size_t chunk);

size_t		ft_align(size_t request_size);

t_arena		*ft_arena_init(size_t chunk);
#endif