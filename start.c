#include "so_long.h"

void	init_image(void *mlx, t_image *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size.x, &img->size.y);
	img->addr  = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->line_size, &img->endian);
}

void	game_images_init(t_game *game)
{
	t_sprite_elem	*next_item;

	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "start : failed to initialize mlx");
	mlx_get_screen_size(game->mlx, &game->screen_res.x, &game->screen_res.y);
	if (game->map_size.x > game->screen_res.x || game->map_size.y > game->screen_res.y)
		error(game, "map is too big for screen resolution");
	game->window = mlx_new_window(game->mlx, game->map_size.x , game->map_size.y, "so_long");
	init_image(game, game->floor, "grass.xpm");
	init_image(game, game->player, "puck.xpm");
	init_image(game, game->first_item->image, "snail.xpm");
	next_item = game->first_item->next;
	while (next_item != game->first_item)
	{
		init_image(game, next_item->image, "snail.xpm");
		next_item = next_item->next;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->pos.x, game->player->pos.y);
}

void	start(t_game *game)
{
	get_positions(game);
	game_images_init(game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop_hook(game->mlx, ft_update, game);
}
