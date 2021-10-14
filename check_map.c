/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:28:33 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 18:04:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_wall_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			error(game, INVALID_CHAR);
		if (line[i] != WALL)
			error(game, NOT_CLOSED);
		i++;
	}
}

static void	check_middle_line(t_game *game, char *line, size_t line_len)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			error(game, INVALID_CHAR);
		if (i == 0 || i == line_len)
		{
			if (line[i] != WALL)
				error(game, NOT_CLOSED);
		}
		i++;
	}
}

void	check_map(t_game *game, char **map)
{
	int		y;
	size_t	line_len;
	size_t	next_line_len;

	y = 0;
	line_len = ft_strlen(map[y]);
	while (map[y])
	{
		next_line_len = ft_strlen(map[y]);
		if (line_len == 0)
			error(game, EMPTY_LINE);
		if (y == 0 || y == game->map_size->y)
			check_wall_line(game, map[y]);
		else
			check_middle_line(game, map[y], line_len);
		if (next_line_len != line_len)
			error(game, RECTANGLE_SHAPE);
		y++;
	}
	game->map_size->x = line_len;
}
