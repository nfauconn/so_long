/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:15:17 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 20:49:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *g, t_image *disp, t_image img, t_v map)
{
	t_double_vector		tile;
	t_double_vector		color_pos;
	t_double_vector		pixel_pos;
	char				*color;
	int					tile_sz;

	tile_sz = g->tile_size;
	tile.y = 0;
	while (tile.y < tile_sz)
	{
		tile.x = 0;
		while (tile.x < tile_sz)
		{
			color_pos.x = img.size->x * (float)(tile.x / tile_sz);
			color_pos.y = img.size->y * (float)(tile.y / tile_sz);
			color = get_pixel_color(img, color_pos.x, color_pos.y);
			pixel_pos.x = map.x * tile_sz + tile.x;
			pixel_pos.y = map.y * tile_sz + tile.y;
			put_pixel_color(disp, pixel_pos.x, pixel_pos.y, color);
			tile.x++;
		}
		tile.y++;
	}
}

void	draw_display(t_game *game, t_image *display, char **map)
{
	t_v			pos;
	t_image		img;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			img = which_background(game, game->map[pos.y][pos.x]);
			draw_tile(game, display, img, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_sprite_list(t_game *game, t_image *disp, t_sprite *sprite)
{
	t_sprite	*tmp;

	draw_tile(game, disp, *sprite->image, *sprite->image->pos);
	tmp = sprite->next;
	while (tmp != sprite)
	{
		draw_tile(game, disp, *tmp->image, *tmp->image->pos);
		tmp = tmp->next;
	}
}

void	draw_window(t_game *game)
{
	draw_display(game, game->display, game->map);
	draw_tile(game, game->display, *game->player, *game->player->pos);
	draw_sprite_list(game, game->display, game->first_exit);
	if (game->item_nb != 0)
		draw_sprite_list(game, game->display, game->item);
}
