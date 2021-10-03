#include "so_long.h"
/*
static void	get_player_pos(t_game *game)
{
	int		x;
	int		y;
	size_t	count;

	count = 0;
	y = 1;
	while (game->map[y])
	{
		x = 1;
		while(game->map[y][x])
		{		
			ft_printf("ok\n");
			if (game->map[y][x] == 'P')
			{
				count++;
				game->player->pos.x = x;
				game->player->pos.y = y;
			}
			x++;
		}
		y++;
	}*/
/*	if (count == 0)
		error_free(game, "found no player position in map");
	if (count > 1)
		error_free(game, "found multiple player position in map");
	ft_printf("player_position = %d, %d\n", game->player->position.x, game->player->position.y);
}
*/
void	get_positions(t_game *game)
{(void)game;
//	get_player_pos(game);
}
