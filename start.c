#include "so_long.h"

void	start(t_game *game)
{
	draw_window(game);
//	mlx_loop_hook(game->mlx, update, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
}
