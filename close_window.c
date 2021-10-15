/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:05:07 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 13:11:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_sprite_list(void *mlx, t_sprite *first_elem)
{
	t_sprite	*tmp;

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
	mlx_destroy_image(game->mlx, game->floor->ptr);
	mlx_destroy_image(game->mlx, game->player->ptr);
	destroy_sprite_list(game->mlx, game->first_exit);
	if (game->item_nb != 0)
		destroy_sprite_list(game->mlx, game->item);
}

static void	destroy_display(t_game *game)
{
	mlx_destroy_image(game->mlx, game->display->ptr);
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
