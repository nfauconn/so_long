#include "so_long.h"

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
	free_game(game);
	exit(0);
}
