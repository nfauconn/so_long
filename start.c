#include "so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr  = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	start(t_game *game)
{
	get_positions(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error("start : failed to initialize mlx");
	game->window = mlx_new_window(game->mlx, 500, 500, "so_long");

	game->avatar = ft_new_sprite(game->mlx, "./puck.xpm");
	mlx_put_image_to_window(game->mlx, game->window, game->avatar.ptr, game->avatar.position.x, game->avatar.position.y);
	game->item = ft_new_sprite(game->mlx, "./snail.xpm");
	game->item.position.x = 120;
	game->item.position.y = 120;
	mlx_put_image_to_window(game->mlx, game->window, game->item.ptr, game->item.position.x, game->item.position.y);


	mlx_hook(game->window, 17, 0, close_w, game);

	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop_hook(game->mlx, ft_update, game);
}
