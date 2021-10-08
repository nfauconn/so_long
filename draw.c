#include "so_long.h"

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map[y][x])
		return ;
}

void	draw_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}