#include "so_long.h"

int	close_w(t_game *game)
{
	mlx_destroy_image(game->mlx, game->avatar.ptr);
	mlx_destroy_image(game->mlx, game->item.ptr);
	mlx_destroy_window(game->mlx, (void *)game->window);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	free_map(game);
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
		game->avatar.position.y -= game->avatar.size.y;
	else if (key == LEFT)
		game->avatar.position.x -= game->avatar.size.x;
	else if (key == DOWN)
		game->avatar.position.y += game->avatar.size.y;
	else if (key == RIGHT)
		game->avatar.position.x += game->avatar.size.x;
//	mlx_put_image_to_window(game->mlx, game->window, game->avatar.ptr, game->avatar.position.x, game->avatar.position.y);
	return (0);
}

int	ft_update(t_game *game)
{
	static int	frame;

	frame++;
	if (frame == 2000)
	{
		game->item.position.y += 1;
		game->avatar.position.y += 1;
	}
	else if (frame >= 2000 * 2)
	{
		game->item.position.y -= 1;
		game->avatar.position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->avatar.ptr, game->avatar.position.x, game->avatar.position.y);
	mlx_put_image_to_window(game->mlx, game->window, game->item.ptr, game->item.position.x, game->item.position.y);
	return (0);
}
