#include "so_long.h"
/*
static void	display_img_values(t_image *img, char *name)
{
	ft_printf("%s_pos = %d, %d      ||      %s_size = %d, %d\n", name, img->pos->x, img->pos->y, name, img->size->x, img->size->y);
}

static void	display_values(t_game *game)
{
	t_sprite_elem *tmp;

	int y = 0;
	while (game->map[y])
	{
		ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
		y++;
	}
	ft_printf("game->map[%d] = |%s|\n", y, game->map[y]);
	display_img_values(game->background, "bkgd");
	display_img_values(game->player, "plyr");
	display_img_values(game->ground, "grnd");
	display_img_values(game->wall, "wall");

	display_img_values(game->first_item->image, "item");
	tmp = game->first_item->next;
	while (tmp != game->first_item)
	{
		display_img_values(tmp->image, "item");
		tmp = tmp->next;
	}

	display_img_values(game->first_exit->image, "exit");
	tmp = game->first_exit->next;
	while (tmp != game->first_exit)
	{
		display_img_values(tmp->image, "exit");
		tmp = tmp->next;
	}

	ft_printf("tile_size = %d\n", game->tile_size);
	ft_printf("char per tile (tile_size / 32) = %d\n", game->tile_size / 32);
	ft_printf("screen_res = %dx%d\n", game->screen_res->x, game->screen_res->y);
	ft_printf("map_size = %dx%d\n", game->map_size->x, game->map_size->y);
}
*/
void	start(t_game *game)
{
//	display_values(game);
	draw_window(game);
//	mlx_loop_hook(game->mlx, update, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
}
