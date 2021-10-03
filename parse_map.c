#include "so_long.h"

static void	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		y;

	y = game->map_size.y;
	line = NULL;
	fd = open(file, O_RDONLY);
	ft_printf("game->map_size.y = %d\n", game->map_size.y);

	while (y >= 0)
	{
		ft_printf("y = %d\n", y);
		get_next_line(fd, &line);
		*game->map = ft_strdup(line);
		game->map++;
		y--;
		free(line);
		line = NULL;
	}
}

static t_bool	alloc_lines(char *file, t_game *game)
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
//	game->map = (char **)malloc(sizeof(char *) * (game->map_size.y));
//	if (!game->map)
//		error("malloc failure on alloc_colums");
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
