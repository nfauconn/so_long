#include "so_long.h"

static void	check_wall_line(t_game *game, char *line)
{
	while (*line)
	{
		if (!ft_strchr("01CEP", line[i]))
			error_free(game, "invalid character in map");
		if (*line != '1')
			error_free(game, "map not closed");
		line++;
	}
}

static void	check_middle_line(t_game *game, char *line, size_t line_len)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			error_free(game, "invalid character in map\nformat :\n- 1 for walls\n- 0 for empty space\n- P for player's starting position\n- C for items he will pick\n- E for exit");
		if (i == 0 || i == line_len)
		{
			if (line[i] != '1')
				error_free(game, "map not closed");
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	int		y;
	size_t	map_width;
	size_t	line_len;
	int		last_line;

	y = 0;
	map_width = ft_strlen(*game->map);
	last_line = ft_array_size(game->map) - 1;
	while (game->map[y])
	{
		line_len = ft_strlen(game->map[y]);
		if (line_len == 0)
			error_free(game, "empty line in map");
		if (y == 0 || y == last_line)
			check_wall_line(game, game->map[y]);
		else
			check_middle_line(game, game->map[y], line_len);
		if (line_len != map_width)
			error_free(game, "map must be a rectangle");
		y++;
	}
}
