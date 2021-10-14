/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tile_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:06:32 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 18:06:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	which_background(t_game *game, char tile)
{
	if (tile == '1')
		return (*game->wall);
	else
		return (*game->ground);
}
