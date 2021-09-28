#include "so_long.h"

int	close_w(t_game *game)
{
	mlx_destroy_window(game->mlx, (void *)game->window);
	exit(0);
	return (0);
}

int	key_hooked(int key, t_game *game)
{
	ft_printf("keycode = %d\n", key);
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
		game->collectable.position.y += 1;
		game->avatar.position.y += 1;
		game->ennemy.position.y += 1;
	}
	else if (frame >= 2000 * 2)
	{
		game->collectable.position.y -= 1;
		game->avatar.position.y -= 1;
		game->ennemy.position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->avatar.ptr, game->avatar.position.x, game->avatar.position.y);
	mlx_put_image_to_window(game->mlx, game->window, game->collectable.ptr, game->collectable.position.x, game->collectable.position.y);
	mlx_put_image_to_window(game->mlx, game->window, game->ennemy.ptr, game->ennemy.position.x, game->ennemy.position.y);
	return (0);
}
