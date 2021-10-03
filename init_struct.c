#include "so_long.h"

static void	init_image(t_image *image)
{
/*	t_image	*image;
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (0);
*/	image->ptr = NULL;
	image->size.x = 0;
	image->size.y = 0;
	image->pos.x = 0;
	image->pos.y = 0;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
//	return (image);
}

void	init_game_struct(t_game *game)
{
/*	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("malloc error in init_game_struct");
*/	game->mlx = NULL;
	game->map = NULL;
	game->map_size.x = 0;
	game->map_size.y = 0;
	game->window = NULL;
	init_image(game->player);
//	if (!game->player)
//		error_free(game, "mem alloc of an image failed");
//	return (game);
}