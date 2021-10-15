/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:03:18 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 13:07:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_line(t_game *game, char *line, size_t len, int y)
{
	int	x;

	game->map[y] = (char *)malloc(sizeof(char) * (len + 1));
	x = 0;
	while (line[x])
	{
		game->map[y][x] = line[x];
		x++;
	}
	game->map[y][x] = '\0';
}

static int	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		y;
	int		ret_gnl;

	y = 0;
	ret_gnl = 1;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (y <= game->map_size->y)
	{
		ret_gnl = get_next_line(fd, &line);
		if (!line && y == game->map_size->y)
		{
			game->map[y] = 0;
			break ;
		}
		else if (!line)
			game->map[y] = 0;
		else
			fill_line(game, line, ft_strlen(line), y);
		ft_strdel(&line);
		y++;
	}
	return (1);
}

static t_ull	count_lines(t_game *game, char *file)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (FAILURE);
	game->map_size->y = 1;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (FAILURE);
		if (ret == 0)
			break ;
		game->map_size->y++;
		ft_strdel(&line);
	}
	close(fd);
	return (SUCCESS);
}

void	parse_map(t_game *game, char *file)
{
	if (!ft_strend_cmp(file, BER_EXT))
		error(game, INVALID_FORMAT);
	if (count_lines(game, file) == FAILURE)
		error(game, WRONG_FD);
	game->map = (char **)malloc(sizeof(char *) * (game->map_size->y + 1));
	if (!game->map)
		error(game, MAP_ALLOC_ERR);
	fill_map(game, file);
	if (!*game->map)
		error(game, EMPTY_LINE);
	check_map(game, game->map);
	get_positions(game);
}
