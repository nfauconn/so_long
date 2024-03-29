/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:55 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:31:46 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_next_frame(t_game *game)
{
	draw_window(game);
	mlx_put_image_to_window(game->mlx, game->window, game->display->ptr, 0, 0);
	return (1);
}

void	start(t_game *game)
{
	draw_window(game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
}
