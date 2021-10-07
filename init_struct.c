#include "so_long.h"

t_vector	*init_vector(t_game *game)
{
	t_vector	*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		error(game, "mem alloc failed in init_vector");
	vector->x = 0;
	vector->y = 0;
	return (vector);
}

t_image	*init_image_struct(t_game *game)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		error(game, "mem alloc failed in init_image_struct");
	image->ptr = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
	image->size = init_vector(game);
	image->pos = init_vector(game);
	return (image);
}

static t_sprite_elem	*init_first_sprite_elem(t_game *game)
{
	t_sprite_elem	*first_elem;

	first_elem = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
	if (!first_elem)
		error(game, "mem alloc failed in init_sprite_elem");
	first_elem->image = init_image_struct(game);
	first_elem->prev = first_elem;
	first_elem->next = first_elem;
	return (first_elem);
}

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->window = NULL;
	game->tile_size = 0;
	game->map_size = init_vector(game);
	game->screen_res = init_vector(game);
	game->display = init_image_struct(game);
	game->floor = init_image_struct(game);
	game->player = init_image_struct(game);
	game->exit = init_image_struct(game);
	game->first_item = init_first_sprite_elem(game);
}