#include "so_long.h"

void	adapt_to_tile(t_game *game)
{
	game->map_size->x *= game->tile_size;
	game->map_size->y *= game->tile_size;
}

void	init_image(t_game *game, void *mlx, t_image *img, char *path)
{(void)game;
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size->x, &img->size->y);
//	img->size->x = game->tile_size;
//	img->size->y = game->tile_size;
//	img->addr  = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size, &img->endian);
}

void	init_game_images(t_game *game)
{
	t_sprite_elem	*next_item;

	init_image(game, game->mlx, game->floor, "textures/grass.xpm");
	init_image(game, game->mlx, game->player, "textures/puck.xpm");
	init_image(game, game->mlx, game->exit, "textures/exit.xpm");
	init_image(game, game->mlx, game->first_item->image, "textures/snail.xpm");
	next_item = game->first_item->next;
	while (next_item != game->first_item)
	{
		init_image(game, game->mlx, next_item->image, "textures/snail.xpm");
		next_item = next_item->next;
	}
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "start : failed to initialize mlx");
	mlx_get_screen_size(game->mlx, &game->screen_res->x, &game->screen_res->y);
	if (game->map_size->x > game->screen_res->x || game->map_size->y > game->screen_res->y)
		error(game, "map is too big for screen resolution");
	game->tile_size = get_tile_size(game->map_size, game->screen_res);
	adapt_to_tile(game);
	game->window = mlx_new_window(game->mlx, game->map_size->x, game->map_size->y, "so_long");
	game->background->ptr = mlx_new_image(game->mlx, game->map_size->x, game->map_size->y);
	game->background->size->x = game->map_size->x;
	game->background->size->y = game->map_size->y;
	color_background(game->background, new_color(204, 204, 255, 0));
	mlx_hook(game->window, 17, 0, close_w, game);
}
