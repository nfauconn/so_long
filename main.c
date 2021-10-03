#include "so_long.h"

//int	main()
int	main(int argc, char **argv)
{
	t_game	game;

//	init_game_struct(&game);
	if (parse_map(argc, argv[1], &game) == SUCCESS)
	{
		while (game.map)
		{
			ft_printf("|%s|\n", *game.map);
			game.map++;
		}
		start(&game);
//		mlx_loop(game.mlx);
	}
	return (0);
}
