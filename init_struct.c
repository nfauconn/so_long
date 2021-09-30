#include "so_long.h"

static void	init_vector(t_vector *vector)
{
	vector->x = 0;
	vector->y = 0;
}

static void	init_image(t_image *image)
{
	image->ptr = NULL;
	init_vector(&image->size);
	init_vector(&image->position);
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
}

void	init_game_struct(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("malloc error in init_game_struct");
	game->mlx = NULL;
	game->map = NULL;
	game->window = NULL;
	init_image(&game->avatar);
	init_image(&game->item);
}