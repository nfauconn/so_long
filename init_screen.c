/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:18 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 13:11:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game *game, void *mlx, t_image *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->size->x, &img->size->y);
	if (!img->ptr)
		error(game, "init_image : image reading has failed");
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bits_per_pixel, &img->size_line, &img->endian);
}

void	init_image_list(t_game *game, t_sprite *first_sprite, char *tex)
{
	t_sprite	*tmp;

	init_image(game, game->mlx, first_sprite->image, tex);
	tmp = first_sprite->next;
	while (tmp != first_sprite)
	{
		init_image(game, game->mlx, tmp->image, tex);
		tmp = tmp->next;
	}
}

void	init_display(t_game *game, t_image *disp)
{
	disp->ptr = mlx_new_image(game->mlx,
			disp->size->x, disp->size->y);
	disp->addr = mlx_get_data_addr(disp->ptr,
			&disp->bits_per_pixel, &disp->size_line, &disp->endian);
	init_image(game, game->mlx, game->wall, "textures/wallnothing.xpm");
	init_image(game, game->mlx, game->floor, "textures/floor.xpm");
	init_image(game, game->mlx, game->player, "textures/puck.xpm");
	init_image_list(game, game->first_exit, "textures/stairs.xpm");
	init_image_list(game, game->item, "textures/snail.xpm");
}

void	init_window(t_game *game, t_v *res, t_v *map_sz, int *tile_sz)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, MLX_INIT_FAILED);
	mlx_get_screen_size(game->mlx, &res->x, &res->y);
	if (map_sz->x > res->x || map_sz->y > res->y)
		error(game, "map is too big for screen resolution");
	*tile_sz = get_tile_size(*map_sz, *res);
	*res = operate_vector(*map_sz, '*', *tile_sz);
	*game->display->size = *game->screen_res;
	game->window = mlx_new_window(game->mlx, res->x, res->y, "so_long");
}

void	init_screen(t_game *game)
{
	init_window(game, game->screen_res, game->map_size, &game->tile_size);
	init_display(game, game->display);
}
