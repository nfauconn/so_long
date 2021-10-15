/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:58:45 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 13:11:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_v	*init_vector(t_game *game)
{
	t_v	*vector;

	vector = (t_v *)malloc(sizeof(t_v));
	if (!vector)
		error(game, "mem alloc failed in init_vector");
	vector->x = 0;
	vector->y = 0;
	return (vector);
}

t_image	*init_image_struct(t_game *game, char type)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		error(game, "mem alloc failed in init_image_struct");
	image->ptr = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->size_line = 0;
	image->endian = 0;
	image->type = type;
	image->size = init_vector(game);
	image->pos = init_vector(game);
	image->px_per_tile = init_vector(game);
	return (image);
}

static t_sprite	*init_first_sprite(t_game *game, char sprite)
{
	t_sprite	*first_elem;

	first_elem = (t_sprite *)malloc(sizeof(t_sprite));
	if (!first_elem)
		error(game, "mem alloc failed in init_sprite");
	first_elem->image = init_image_struct(game, sprite);
	first_elem->prev = first_elem;
	first_elem->next = first_elem;
	return (first_elem);
}

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->window = NULL;
	game->tile_size = 0;
	game->map_size = init_vector(game);
	game->screen_res = init_vector(game);
	game->display = init_image_struct(game, DISPLAY);
	game->wall = init_image_struct(game, WALL);
	game->floor = init_image_struct(game, FLOOR);
	game->player = init_image_struct(game, PLAYER);
	game->first_exit = init_first_sprite(game, EXIT);
	game->item = init_first_sprite(game, ITEM);
	game->item_nb = 0;
	game->exit_nb = 0;
}
