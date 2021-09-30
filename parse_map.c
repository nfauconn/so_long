#include "so_long.h"

static void	fill_map(t_game *game, char *file)
{
	int		fd;
	int		ret_gnl;
	char	*line;
	int		y;

	y = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	ret_gnl = 1;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(fd, &line);
		game->map[y] = ft_strdup(line);
		y++;
		free(line);
		line = NULL;
	}
	game->map[y] = 0;
}

static t_bool	alloc_lines(char *file, t_game *game)
{
	int		fd;
	int		nb_lines;
	int		ret;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (FAILURE);
	nb_lines = 1;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (FAILURE);
		if (ret == 0)
			break ;
		if (c == '\n')
			nb_lines++;
	}
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * nb_lines);
	if (!game->map)
		error("malloc failure on alloc_colums");
	return (SUCCESS);
}

t_bool	parse_map(int argc, char *file, t_game *game)
{
	if (argc != 2)
		error("invalid number of arg, must be 2 : <pgm> <map>");
	if (!ft_strend_cmp(file, ".ber"))
		error("invalid format for the map : please use *.ber");
	if (alloc_lines(file, game) == FAILURE)
		error ("wrong fd : please verify that file exists / is not a directory");
	fill_map(game, file);
	check_map(game);
	return (SUCCESS);
}
