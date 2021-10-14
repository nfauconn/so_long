/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:55 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 23:19:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_next_frame(t_game *game)
{
	draw_window(game);
	return (1);
}

void	start(t_game *game)
{
	draw_window(game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_hook(game->window, Expose, ExposureMask, render_next_frame, game);
	mlx_hook(game->window, 17, 0, close_w, game);
	mlx_key_hook(game->window, key_hooked, game);
	mlx_loop(game->mlx);
}
