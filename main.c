#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	parse_map(&game, argc, argv[1]);
	start(&game);
	free_game(&game);
	return (0);
}
