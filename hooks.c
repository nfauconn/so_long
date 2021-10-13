/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:14:39 by user42            #+#    #+#             */
/*   Updated: 2021/10/13 13:08:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	del_top(t_game *game, t_sprite_elem *item)
{
	t_sprite_elem	*tmp;
	t_sprite_elem	**top;

	top = &game->first_item;
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
			free(tmp);
		}
	}
}
*/
void	delete_item(t_game *game, int x, int y)
{
	t_sprite_elem	*tmp;
	t_sprite_elem	**top;

	while (game->first_item->image->pos->x != x && game->first_item->image->pos->y != y)
		game->first_item = game->first_item->next;
	top = &game->first_item;
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
			free(tmp);
		}
	}
//	del_top(game, game->first_item);
}

int	check_dest(t_game *game, t_image *player, char **map, int x, int y)
{
	int				item_no;
	t_vector		dest;

	item_no = 0;
	dest = *player->pos;
	if (map[dest.y][dest.x] == EXIT)
	{
		if (game->item_nb == 0)
			close_w(game);
		ft_printf("sorry you must have collected all snails before leaving\n");
		player->pos->x = x;
		player->pos->y = y;
		return (0);
	}
	else if (map[dest.y][dest.x] == ITEM)
	{
		delete_item(game, x, y);
		game->map[dest.y][dest.x] = '0';
		game->item_nb--;
	}
	return (1);
}

void	update_positions(t_game *game, t_image *player, char **map, int key)
{
	static int	moves = 0;
	int			x;
	int			y;

	x = player->pos->x;
	y = player->pos->y;
	if ((key == UP || key == W) && map[y - 1][x] != WALL)
	{
		player->pos->y -= 1;
		if (check_dest(game, player, map, x, y) == SUCCESS)
			ft_printf("moves = %d\n", moves++);
	}
	else if ((key == LEFT || key == A) && map[y][x - 1] != WALL)
	{
		player->pos->x -= 1;
		if (check_dest(game, player, map, x, y) == SUCCESS)
				ft_printf("moves = %d\n", moves++);
	}
	else if ((key == DOWN || key == S) && map[y + 1][x] != WALL)
	{
		player->pos->y += 1;
		if (check_dest(game, player, map, x, y) == SUCCESS)
				ft_printf("moves = %d\n", moves++);
	}
	else if ((key == RIGHT || key == D) && map[y][x + 1] != WALL)
	{
		player->pos->x += 1;
		if (check_dest(game, player, map, x, y) == SUCCESS)
				ft_printf("moves = %d\n", moves++);
	}
}
int	key_hooked(int key, t_game *game)
{
	if (key == ECHAP)
		close_w(game);
	else
		update_positions(game, game->player, game->map, key);
	mlx_clear_window(game->mlx, game->window);
	draw_window(game);
	mlx_put_image_to_window(game->mlx, game->window, game->background->ptr, 0, 0);
	return (0);
}

int	update(t_game *game)
{

	(void)game;
	mlx_clear_window(game->mlx, game->window);
	static int	frame;

	frame++;
	if (frame == 2000)
	{
		game->player->pos->y += 1 / game->tile_size;
	}
	else if (frame >= 2000 * 2)
	{
		game->player->pos->y -= 1 / game->tile_size;
		frame = 0;
	}
	draw_window(game);
	mlx_put_image_to_window(game->mlx, game->window, game->background, 0, 0);
	return (0);
}
