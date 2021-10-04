#include "so_long.h"

//int	main()
int	main(int argc, char **argv)
{
	t_game	game;

//	init_game_struct(&game);
	parse_map(argc, argv[1], &game);
	if (!game.map)
		error_free(&game, "map is empty");

	int y = 0;
	while (game.map[y])
	{
		ft_printf("game->map[%d] = |%s|\n", y, game.map[y]);
		y++;
	}
	ft_printf("game->map[%d] = |%s|\n", y, game.map[y]);
	start(&game);
//	mlx_loop(game.mlx);
	return (0);
}
