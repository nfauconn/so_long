#include "so_long.h"

t_vector	operate_vector(t_vector vector, char operation, int nb)
{
	t_vector	res;

	if (operation == '*')
	{
		res.x = vector.x * nb;
		res.y = vector.y * nb;
	}
	if (operation == '/')
	{
		res.x = vector.x / nb;
		res.y = vector.y / nb;
	}
	if (operation == '+')
	{
		res.x = vector.x + nb;
		res.y = vector.y + nb;
	}
	if (operation == '-')
	{
		res.x = vector.x - nb;
		res.y = vector.y - nb;
	}
	return (res);
}

void	init_image(t_game *game, void *mlx, t_image *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size->x, &img->size->y);
//	img->size->x = game->pixels_per_tile;
//	img->size->y = game->pixels_per_tile;
	img->addr  = mlx_get_data_addr(img->ptr, &img->BPP, &img->CPL, &img->endian);
}

void	init_game_images(t_game *game)
{
	t_sprite_elem	*next_item;

	init_image(game, game->mlx, game->wall, "textures/wall.xpm");
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
	t_vector	window_px_nb;

	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "start : failed to initialize mlx");
	mlx_get_screen_size(game->mlx, &game->screen_res->x, &game->screen_res->y);
	if (game->map_size->x > game->screen_res->x || game->map_size->y > game->screen_res->y)
		error(game, "map is too big for screen resolution");
	game->pixels_per_tile = get_pixels_per_tile(*(game->map_size), *(game->screen_res));
	window_px_nb = operate_vector(*(game->map_size), '*', game->pixels_per_tile);
	game->window = mlx_new_window(game->mlx, window_px_nb.x, window_px_nb.y, "so_long");
	game->background->ptr = mlx_new_image(game->mlx, window_px_nb.x, window_px_nb.y);
	*(game->background->size) = window_px_nb;
//	color_background(game->background, new_color(204, 204, 255, 0));
	mlx_hook(game->window, 17, 0, close_w, game);
}
