#include "so_long.h"
/*
int	close_w(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player->image->ptr);
	mlx_destroy_window(game->mlx, (void *)game->window);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}

int	key_hooked(int key, t_game *game)
{
//	ft_printf("keycode = %d\n", key);
	if (key == ECHAP)
		close_w(game);
	mlx_clear_window(game->mlx, game->window);
	if (key == UP)
		game->player->position->y -= game->player->size->y;
	else if (key == LEFT)
		game->player->position->x -= game->player->size->x;
	else if (key == DOWN)
		game->player->position->y += game->player->size->y;
	else if (key == RIGHT)
		game->player->position->x += game->player->size->x;
//	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->position->x, game->player->position->y);
	return (0);
}

int	ft_update(t_game *game)
{
	static int	frame;

	frame++;
	if (frame == 2000)
	{
		game->item->position->y += 1;
		game->player->position->y += 1;
	}
	else if (frame >= 2000 * 2)
	{
		game->item->position->y -= 1;
		game->player->position->y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->position->x, game->player->position->y);
	mlx_put_image_to_window(game->mlx, game->window, game->item->ptr, game->item->position->x, game->item->position->y);
	return (0);
}
*/