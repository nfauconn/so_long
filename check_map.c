#include "so_long.h"

static void	check_wall_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			error(game, "invalid character in map");
		if (line[i] != '1')
			error(game, "map not closed");
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
			error(game, "invalid character in map\nformat :\n- 1 for walls\n- 0 for empty space\n- P for player's starting position\n- C for items he will pick\n- E for exit");
		if (i == 0 || i == line_len)
		{
			if (line[i] != '1')
				error(game, "map not closed");
		}
		i++;
	}
}

void	check_map(t_game *game, char **map)
{
	int		y;
	size_t	line_len;

	y = 0;
	while (map[y])
	{
		line_len = ft_strlen(map[y]);
		if (line_len == 0)
			error(game, "empty line in map");
		if (y == 0 || y == game->map_size->y)
			check_wall_line(game, map[y]);
		else
			check_middle_line(game, map[y], line_len);
		if (line_len != (size_t)game->map_size->x)
			error(game, "map must be a rectangle");
		y++;
	}
}
