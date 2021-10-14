/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:32:43 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 18:43:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_new_node(t_game *game, t_sprite *sprite, t_v pos, char c)
{
	t_sprite	*new;

	new = (t_sprite *)malloc(sizeof (t_sprite));
	if (!new)
		error(game, "malloc error in insert_new_node");
	new->next = sprite;
	new->prev = sprite->prev;
	sprite->prev = new;
	new->prev->next = new;
	new->image = init_image_struct(game, c);
	new->image->pos->x = pos.x;
	new->image->pos->y = pos.y;
}

static int	get_elem_pos(t_game *game, t_sprite *sprite, char letter)
{
	t_v		pos;
	size_t	count;

	count = 0;
	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == letter)
			{
				count++;
				if (count == 1)
					*sprite->image->pos = pos;
				else
					insert_new_node(game, sprite, pos, letter);
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		error(game, MISSING_SPRITE);
	return (count);
}

static void	get_sprite_pos(t_game *game, t_image *sprite, int letter)
{
	t_v		pos;
	size_t	count;

	count = 0;
	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == letter)
			{
				count++;
				sprite->pos->x = pos.x;
				sprite->pos->y = pos.y;
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		error(game, MISSING_SPRITE);
	if (count > 1 && letter == PLAYER)
		error(game, MULTIPLE_PLAYER);
}

void	get_positions(t_game *game)
{
	get_sprite_pos(game, game->player, PLAYER);
	game->exit_nb = get_elem_pos(game, game->first_exit, EXIT);
	game->item_nb = get_elem_pos(game, game->item, ITEM);
}

int	get_tile_size(t_v img_size, t_v res)
{
	t_v	size;

	size.x = res.x / img_size.x;
	size.y = res.y / img_size.y;
	if (size.x <= size.y)
	{
		if (size.y * img_size.x > res.x)
			size.y = (res.x / img_size.x) - 1;
	}
	else
	{
		if (size.x * img_size.y > res.y)
			size.x = (res.y / img_size.y) - 1;
	}
	if (size.x < size.y)
	{
		if (size.x < 1)
			return (1);
		return (size.x);
	}
	return (size.y);
}
