#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && argv[1])
	{
		init_game_struct(&game);
		parse_map(&game, argv[1]);
		init_screen(&game);
		start(&game);
		free_game(&game);
	}
	else
		error(&game, "invalid number of arg, must be 2 : <pgm> <map>");
	return (0);
}
