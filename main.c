#include "so_long.h"

int main()
{
	t_game	game;

	start(&game);
	mlx_loop(game.mlx);
	return (0);
}
