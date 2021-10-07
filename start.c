#include "so_long.h"

static void	display_img_values(t_image *img, char *name)
{
	ft_printf("%s_pos = %d, %d      ||      %s_size = %d, %d\n", name, img->pos->x, img->pos->y, name, img->size->x, img->size->y);
}

static void	display_values(t_game *game)
{
	int y = 0;
	while (game->map[y])
	{
		ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
		y++;
	}
	ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
	
	display_img_values(game->display, "disp");
	display_img_values(game->player, "play");
	display_img_values(game->floor, "floo");
	display_img_values(game->exit, "exit");

	t_sprite_elem *tmp;
	tmp = game->first_item;
	while (tmp->next != game->first_item)
	{
		display_img_values(tmp->image, "item");
		tmp = tmp->next;
	}
	display_img_values(tmp->image, "item");
}

void	start(t_game *game)
{
	get_positions(game);
	init_window(game);
	init_game_images(game);
	display_values(game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
//	mlx_loop_hook(game->mlx, ft_update, game);
}
