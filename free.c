#include "so_long.h"

static void	free_map(t_game *game)
{
	int y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map[y]);
	free(game->map);
	game->map = NULL;
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game);
	if (game->player)
		free(game->player);
	free(game);
	game = NULL;
	exit(0);
}
