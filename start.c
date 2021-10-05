#include "so_long.h"

void	init_image(void *mlx, t_image *img, char *path)
{
	ft_printf("mlx = %p\n", mlx);
	ft_printf("path = %s\n", path);
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size.x, &img->size.y);
	img->addr  = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->line_size, &img->endian);
	ft_printf("img->size.x = %d\nimg->size.y = %d\n", img->size.x, img->size.y);

}

void	game_images_init(t_game *game)
{
	t_sprite_elem	*next_item;

	game->window = mlx_new_window(game->mlx, game->map_size.x , game->map_size.y, "so_long");
	init_image(game->mlx, game->floor, "./grass.xpm");
	init_image(game->mlx, game->player, "./puck.xpm");
	init_image(game->mlx, game->first_item->image, "./snail.xpm");
	next_item = game->first_item->next;
	while (next_item != game->first_item)
	{
		init_image(game->mlx, next_item->image, "snail.xpm");
		next_item = next_item->next;
	}
	ft_printf("game->player->pos.x = %d\n", game->player->pos.x);
	ft_printf("game->player->pos.y = %d\n", game->player->pos.y);
	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->pos.x, game->player->pos.y);
}

int	get_tile_size(t_game *game, t_vector map_size, t_vector res)
{
	t_vector	size;

	size = (t_vector){.x = res.x / map_size.x, .y = res.y / map_size.y};
	if (size.x <= size.y)
	{
		if (size.y * map_size.x > res.x)
			size.y = (res.x / map_size.x) - 1;
	}
	else
	{
		if (size.x * map_size.y > res.y)
			size.x = (res.y / map_size.y) - 1;
	}
	if (size.x < size.y)
	{
		if (size.x < 1)
			return (1);
		return (size.x);
	}
	return (size.y);
}

void	start(t_game *game)
{
	get_positions(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "start : failed to initialize mlx");
	mlx_get_screen_size(game->mlx, &game->screen_res.x, &game->screen_res.y);
	if (game->map_size.x > game->screen_res.x || game->map_size.y > game->screen_res.y)
		error(game, "map is too big for screen resolution");
	game->tile_size = get_tile_size(game, game->map_size, game->screen_res);
	game_images_init(game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
//	mlx_loop_hook(game->mlx, ft_update, game);
}
