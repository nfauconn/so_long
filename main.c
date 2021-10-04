#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	parse_map(&game, argc, argv[1]);

	int y = 0;
	while (game.map[y])
	{
		ft_printf("game->map[%d] = |%s|\n", y, game.map[y]);
		y++;
	}
	ft_printf("game->map[%d] = |%s|\n", y, game.map[y]);



	start(&game);

//	mlx_loop(game.mlx);
	free_game(&game);

	return (0);
}
