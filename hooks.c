/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:14:39 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 23:18:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_move_key(int key)
{
	if (key == UP || key == W)
		return (UP);
	else if (key == DOWN || key == S)
		return (DOWN);
	else if (key == RIGHT || key == D)
		return (RIGHT);
	else if (key == LEFT || key == A)
		return (LEFT);
	else
		return (0);
}

void	delete_item(t_game *game, int x, int y)
{
	t_sprite	*tmp;
	t_sprite	**top;

	while (game->item->image->pos->x != x && game->item->image->pos->y != y)
		game->item = game->item->next;
	top = &game->item;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			mlx_destroy_image(game->mlx, (*top)->image->ptr);
			free_sprite_list(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			mlx_destroy_image(game->mlx, tmp->image->ptr);
			free_image(tmp->image);
			free(tmp);
		}
	}
}

int	check_dest(t_game *game, t_image *player, t_v previous_pos)
{
	int		item_no;
	t_v		dest;

	item_no = 0;
	dest = *player->pos;
	if (game->map[dest.y][dest.x] == EXIT)
	{
		if (game->item_nb == 0)
			return (2);
		ft_printf("sorry you must have collected all snails before leaving\n");
		*player->pos = previous_pos;
		return (0);
	}
	if (game->map[dest.y][dest.x] == ITEM)
	{
		delete_item(game, dest.x, dest.y);
		game->map[dest.y][dest.x] = '0';
		game->item_nb--;
	}
	if (game->map[dest.y][dest.x] == WALL)
	{
		*player->pos = previous_pos;
		return (0);
	}
	return (1);
}

void	update_positions(t_game *game, t_image *player, int keycode)
{
	static int	moves = 1;
	int			key;
	t_v			previous_pos;
	int			dest_ok;

	previous_pos = *player->pos;
	key = is_move_key(keycode);
	if (key)
	{
		if (key == UP)
			player->pos->y -= 1;
		else if (key == LEFT)
			player->pos->x -= 1;
		else if (key == DOWN)
			player->pos->y += 1;
		else if (key == RIGHT)
			player->pos->x += 1;
		dest_ok = check_dest(game, player, previous_pos);
		if (dest_ok)
			ft_printf("moves = %d\n", moves++);
		if (dest_ok == END)
			ft_printf("you win in %d moves\n", moves);
	}
}

int	key_hooked(int key, t_game *game)
{
	if (key == ECHAP)
		close_w(game);
	else
		update_positions(game, game->player, key);
//	mlx_clear_window(game->mlx, game->window);
	draw_window(game);
	mlx_put_image_to_window(game->mlx, game->window, game->display->ptr, 0, 0);
	return (0);
}
