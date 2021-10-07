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
	
	ft_printf("player_pos = %d, %d\n", game->player->pos.x, game->player->pos.y);
	ft_printf("exit_pos = %d, %d\n", game->exit->pos.x, game->exit->pos.y);
	t_sprite_elem *tmp;
	tmp = game->first_item;
	while (tmp->next != game->first_item)
	{
		ft_printf("item_pos = %d, %d\n", tmp->image->pos.x, tmp->image->pos.y);
		tmp = tmp->next;
	}
	ft_printf("item_pos = %d, %d\n", tmp->image->pos.x, tmp->image->pos.y);
}

void	start(t_game *game)
{
	get_positions(game);
	display_values(game);
	init_window(game);
	init_game_images(game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
//	mlx_loop_hook(game->mlx, ft_update, game);
}
