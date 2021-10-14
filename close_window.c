#include "so_long.h"

static void	destroy_sprite_list(void *mlx, t_sprite_elem *first_elem)
{
	t_sprite_elem	*tmp;

	mlx_destroy_image(mlx, first_elem->image->ptr);
	tmp = first_elem->next;
	while (tmp != first_elem)
	{
		mlx_destroy_image(mlx, tmp->image->ptr);
		tmp = tmp->next;
	}
}

static void	destroy_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall->ptr);
	mlx_destroy_image(game->mlx, game->ground->ptr);
	mlx_destroy_image(game->mlx, game->player->ptr);
	destroy_sprite_list(game->mlx, game->first_exit);
	if (game->item_nb != 0)
		destroy_sprite_list(game->mlx, game->first_item);
}

static void	destroy_display(t_game *game)
{
	mlx_destroy_image(game->mlx, game->background->ptr);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);	
}

int	close_w(t_game *game)
{
	destroy_sprites(game);
	destroy_display(game);
	mlx_loop_end(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}
