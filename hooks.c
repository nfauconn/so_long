#include "so_long.h"

void	destroy_sprites(t_game *game)
{
	t_sprite_elem	*next_item;

	mlx_destroy_image(game->mlx, game->floor->ptr);
	mlx_destroy_image(game->mlx, game->player->ptr);
	mlx_destroy_image(game->mlx, game->exit->ptr);
	mlx_destroy_image(game->mlx, game->first_item->image->ptr);
	next_item = game->first_item->next;
	while (next_item != game->first_item)
	{
		mlx_destroy_image(game->mlx, next_item->image->ptr);
		next_item = next_item->next;
	}
}

int	close_w(t_game *game)
{
	destroy_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}

int	key_hooked(t_game *game, int key)
{
	printf("keycode = %ld\n", (long)key);
	if (key == ECHAP)
		close_w(game);
/*	mlx_clear_window(game->mlx, game->window);
	if (key == UP)
		game->player->pos->y -= game->player->size->y;
	else if (key == LEFT)
		game->player->pos->x -= game->player->size->x;
	else if (key == DOWN)
		game->player->pos->y += game->player->size->y;
	else if (key == RIGHT)
		game->player->pos->x += game->player->size->x;
	mlx_put_image_to_window(game->mlx, game->window, game->background->ptr, 0, 0);
*/	return (0);
}

int	update(t_game *game)
{
	(void)game;
	mlx_put_image_to_window(game->mlx, game->window, game->background, 0, 0);

/*	static int	frame;

	frame++;
	if (frame == 2000)
	{
		game->first_item->pos->y += 1;
		game->player->pos->y += 1;
	}
	else if (frame >= 2000 * 2)
	{
		game->first_item->pos->y -= 1;
		game->player->pos->y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->player->ptr, game->player->pos->x, game->player->pos->y);
	mlx_put_image_to_window(game->mlx, game->window, game->first_item->ptr, game->first_item->pos->x, game->first_item->pos->y);
*/	return (0);
}
