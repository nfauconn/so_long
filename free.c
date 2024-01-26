/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:42:17 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_image *img)
{
	if (img->size)
		free(img->size);
	if (img->pos)
		free(img->pos);
	if (img->px_per_tile)
		free(img->px_per_tile);
	if (img)
		free(img);
}

void	free_sprite_list(t_sprite *first_elem)
{
	t_sprite	**tmp;
	t_sprite	*to_free;

	tmp = &first_elem->next;
	while (*tmp != first_elem)
	{
		free_image((*tmp)->image);
		to_free = *tmp;
		*tmp = (*tmp)->next;
		free(to_free);
	}
	free_image((*tmp)->image);
	free(*tmp);
}

static void	free_2d_table(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab[y]);
	free(tab);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_2d_table(game->map);
	if (game->map_size)
		free(game->map_size);
	if (game->screen_res)
		free(game->screen_res);
	if (game->display)
		free_image(game->display);
	if (game->floor)
		free_image(game->floor);
	if (game->wall)
		free_image(game->wall);
	if (game->player)
		free_image(game->player);
	if (game->first_exit)
		free_sprite_list(game->first_exit);
	if (game->item)
		free_sprite_list(game->item);
	if (game->mlx)
		free(game->mlx);
}
