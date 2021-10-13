#include "so_long.h"

void	draw_tile(t_game *game, t_image *display, t_image img, int startX, int startY)
{
	t_double_vector		tile;
	t_double_vector		color_pos;
	char				*color;
	int					tile_size;

	tile_size = game->tile_size;
	tile.y = 0;
	while (tile.y < tile_size)
	{
		tile.x = 0;
		while (tile.x < tile_size)
		{
			color_pos.x = img.size->x / (100 / ((tile.x / tile_size) * 100.0));
			color_pos.y = img.size->y / (100 / ((tile.y / tile_size) * 100.0));
			color = get_pixel_color(img, color_pos.x, color_pos.y);
			if (img.type == GROUND)
				make_color_transparent(&img, color);
			put_pixel_color(display, startX * tile_size + tile.x, startY * tile_size + tile.y, color);
			tile.x++;
		}
		tile.y++;
	}
}

void	draw_background(t_game *game, t_image *display, char **map)
{
	int	x;
	int	y;
	t_image	img;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			img = which_background(game, game->map[y][x]);
			draw_tile(game, display, img, x, y);
			x++;
		}
		y++;
	}
}

void	draw_sprite(t_game *game, t_image *display, t_image sprite)
{
	draw_tile(game, display, sprite, sprite.pos->x, sprite.pos->y);
}

void	draw_sprite_list(t_game *game, t_image *display, t_sprite_elem *first_sprite)
{
	t_sprite_elem	*tmp;

	draw_sprite(game, display, *first_sprite->image);
	tmp = first_sprite->next;
	while (tmp != first_sprite)
	{
		draw_sprite(game, display, *tmp->image);
		tmp = tmp->next;
	}
}

void	draw_sprites(t_game *game)
{
	draw_sprite(game, game->background, *game->player);
	draw_sprite_list(game, game->background, game->first_exit);
	if (game->item_nb != 0)
		draw_sprite_list(game, game->background, game->first_item);
}

void	draw_window(t_game *game)
{
	draw_background(game, game->background, game->map);
	draw_sprites(game);
}