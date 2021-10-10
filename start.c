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
	display_img_values(game->background, "disp");
	display_img_values(game->player, "play");
	display_img_values(game->floor, "floo");
	display_img_values(game->wall, "wall");
	display_img_values(game->exit, "exit");

	t_sprite_elem *tmp;
	tmp = game->first_item;
	while (tmp->next != game->first_item)
	{
		display_img_values(tmp->image, "item");
		tmp = tmp->next;
	}
	display_img_values(tmp->image, "item");
	ft_printf("pixels_per_tile = %d\n", game->pixels_per_tile);
	ft_printf("char per tile (pixels_per_tile / 32) = %d\n", game->pixels_per_tile / 32);
	ft_printf("screen_res = %dx%d\n", game->screen_res->x, game->screen_res->y);
	ft_printf("map_size = %dx%d\n", game->map_size->x, game->map_size->y);
//	ft_printf("map_size * pixels_per_tile= %dx%d\n", game->map_size->x, game->map_size->y);
	ft_printf("chars_per_line addre background = %d\n", game->background->CPL);
	ft_printf("BPP = %d\n", game->background->BPP);
}

void	start(t_game *game)
{
	get_positions(game);
	init_window(game);
	init_game_images(game);
	draw_window(game);
	display_values(game);
//	mlx_loop_hook(game->mlx, update, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
}
