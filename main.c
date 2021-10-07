#include "so_long.h"

static void	display_values(t_game *game)
{
	int y = 0;
	while (game->map[y])
	{
		ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
		y++;
	}
	ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	parse_map(&game, argc, argv[1]);
	display_values(&game);
	start(&game);
	free_game(&game);
	return (0);
}
