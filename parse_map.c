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
	line = NULL;
	fd = open(file, O_RDONLY);
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(fd, &line);
		game->map[y] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
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

	fd = open(file, O_RDONLY);
	if (!fd)
		return (FAILURE);
	game->map_size.y = 1;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (FAILURE);
		if (ret == 0)
			break ;
		if (c == '\n')
			game->map_size.y++;
	}
	close(fd);
	return (SUCCESS);
}

void	parse_map(int argc, char *file, t_game *game)
{
	if (argc != 2)
		error("invalid number of arg, must be 2 : <pgm> <map>");
	if (!ft_strend_cmp(file, ".ber"))
		error("invalid format for the map : please use *.ber");
	if (count_lines(game, file) == FAILURE)
		error ("wrong fd : please verify that file exists / is not a directory");
	game->map = (char **)malloc(sizeof(char *) * (game->map_size.y + 1));
	if (!game->map)
		error("malloc failure on alloc_colums");
	fill_map(game, file);
	check_map(game, game->map);
}
