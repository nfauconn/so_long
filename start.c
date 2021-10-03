#include "so_long.h"

/*t_image	*ft_new_sprite(void *mlx, char *path)
{
	t_image	*img;

	img = NULL;
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size->x, &img->size->y);
	img->addr  = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->line_size, &img->endian);
	return (img);
}*/

void	start(t_game *game)
{
	get_positions(game);
/*	game->mlx = mlx_init();
	if (!game->mlx)
		error("start : failed to initialize mlx");
	game->window = mlx_new_window(game->mlx, 500, 500, "so_long");

	game->player = ft_new_sprite(game->mlx, "./puck.xpm");
	ft_printf("player_position in start = %d, %d\n", game->player->position->x, game->player->position->y);

	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->position->x, game->player->position->y);
	game->item = ft_new_sprite(game->mlx, "./snail.xpm");
	game->item->position->x = 120;
	game->item->position->y = 120;
	mlx_put_image_to_window(game->mlx, game->window, game->item->ptr, game->item->position->x, game->item->position->y);


	mlx_hook(game->window, 17, 0, close_w, game);

	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop_hook(game->mlx, ft_update, game);*/
}
