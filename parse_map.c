#include "so_long.h"

static void	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		ret_gnl;

	y = 0;
	ret_gnl = 1;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(fd, &line);
		game->map[y] = (char *)malloc(sizeof(char) * (game->map_size->x + 1));
		x = 0;
		while (line[x])
		{
			game->map[y][x] = line[x];
			x++;
		}
		game->map[y][x] = '\0';
		free(line);
		line = NULL;
		y++;
	}
	game->map[y] = 0;
}

static t_bool	count_lines(t_game *game, char *file)
{
	int		fd;
	int		ret;
	char	c;
	int		max_x;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (FAILURE);
	max_x = 0;
	game->map_size->y = 1;
	while (1)
	{
		ret = read(fd, &c, 1);
		max_x++;
		if (ret == -1)
			return (FAILURE);
		if (ret == 0)
			break ;
		if (c == '\n')
		{
			if (max_x > game->map_size->x)
				game->map_size->x = max_x - 1;
			max_x = 0;
			game->map_size->y++;
		}
	}
	close(fd);
	return (SUCCESS);
}

void	parse_map(t_game *game, int argc, char *file)
{
	if (argc != 2)
		error(game, "invalid number of arg, must be 2 : <pgm> <map>");
	if (!ft_strend_cmp(file, ".ber"))
		error(game, "invalid format for the map : please use *.ber");
	if (count_lines(game, file) == FAILURE)
		error(game, "wrong fd : please verify that file exists / is not a directory");
	game->map = (char **)malloc(sizeof(char *) * (game->map_size->y + 1));
	if (!game->map)
		error(game, "malloc failure on alloc_colums");
	fill_map(game, file);
	check_map(game, game->map);
}
