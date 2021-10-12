/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:14:39 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 23:04:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_item(t_game *game, t_sprite_elem *first, int x, int y)
{
	t_sprite_elem	**tmp;

	tmp = &first;
	if (first->image->pos->x == x && first->image->pos->y == y)
	{
		(*tmp = &first->next;
		mlx_destroy_image(game->mlx, first->image->ptr);

	}
	tmp = first->next;
	while (tmp != first)
	{
		if (tmp->image->pos->x == x && tmp->image->pos->y == y)
			return (&tmp);
		tmp = tmp->next;
	}
	return (&tmp);


item = which_item(game->first_item, x, y);
		mlx_destroy_image(game->mlx, *(item->image->ptr));
		*item->next->prev = *item->prev;
		*item->prev->next = *item->next;
		free(item);
}

int	check_dest(t_game *game, t_image *player, char **map, int x, int y)
{
	t_vector		dest;
	t_sprite_elem	**item;

	dest = *player->pos;
	if (map[dest.y][dest.x] == EXIT)
	{
		if (!game->first_item)
			close_w(game);
		ft_printf("sorry you must have collected all snails before leaving\n");
		player->pos->x = x;
		player->pos->y = y;
		return (0);
	}
	else if ((map[dest.y][dest.x] == ITEM) && game->first_item)
	{
		delete_item(game, game->first_item, x, y);
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
