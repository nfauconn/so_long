#include "so_long.h"

void	init_image(t_game *game, void *mlx, t_image *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size->x, &img->size->y);
	if (!img->ptr)
		error(game, "init_image : image reading has failed");
	img->addr = mlx_get_data_addr(img->ptr, &img->BPP, &img->size_line, &img->endian);
}

void	init_image_list(t_game *game, t_sprite_elem *first_sprite, char *texture)
{
	t_sprite_elem	*tmp;

	init_image(game, game->mlx, first_sprite->image, texture);
	tmp = first_sprite->next;
	while (tmp != first_sprite)
	{
		init_image(game, game->mlx, tmp->image, texture);
		tmp = tmp->next;
	}
}

void	init_game_images(t_game *game)
{
	init_image(game, game->mlx, game->wall, "textures/walls.xpm");
	init_image(game, game->mlx, game->ground, "textures/grass.xpm");
	init_image(game, game->mlx, game->player, "textures/puck.xpm");
	init_image_list(game, game->first_exit, "textures/exit.xpm");
	init_image_list(game, game->first_item, "textures/snail.xpm");
}

void	init_display(t_game *game, t_image *display)
{
	*display->size = *game->screen_res;
	display->ptr = mlx_new_image(game->mlx, display->size->x, display->size->y);
	display->addr = mlx_get_data_addr(display->ptr, &display->BPP, &display->size_line, &display->endian);
}

void	init_window(t_game *game, t_vector *screen_res, t_vector *map_size, int *tile_size)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "start : failed to initialize mlx");
	mlx_get_screen_size(game->mlx, &screen_res->x, &screen_res->y);
	if (map_size->x > screen_res->x || map_size->y > screen_res->y)
		error(game, "map is too big for screen resolution");
	*tile_size = get_tile_size(*map_size, *screen_res);
	*screen_res = operate_vector(*map_size, '*', *tile_size);
	game->window = mlx_new_window(game->mlx, screen_res->x, screen_res->y, "so_long");
	mlx_hook(game->window, 17, 0, close_w, game);
}

void	init_screen(t_game *game)
{
	init_window(game, game->screen_res, game->map_size, &game->tile_size);
	init_game_images(game);
	init_display(game, game->background);
	init_display(game, game->sprites);
//	color_background(game->sprites);
}