#include "so_long.h"

void	free_map(t_game *game)
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

void	error(char *s)
{
	ft_putstr_fd("error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	error_free(t_game *game, char *s)
{
	ft_putstr_fd("error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	if (game->map)
		free_map(game);
	exit(0);
}
