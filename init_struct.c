#include "so_long.h"

void	init_vector(t_vector *vector)
{
	vector->x = 0;
	vector->y = 0;
}

t_image	*init_image_struct(void)
{
	t_image	*image;
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (0);
	image->ptr = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
	init_vector(&image->size);
	init_vector(&image->pos);
	return (image);
}

static t_sprite_elem	*init_sprite_elem(void)
{
	t_sprite_elem	*list;
	list = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
	if (!list)
		return (0);
	list->image = init_image_struct();
	list->prev = list;
	list->next = list;
	return (list);
}

void	init_game_struct(t_game *game)
{
/*	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(game, "malloc error in init_game_struct");
*/	game->mlx = NULL;
	game->map = NULL;
	init_vector(&game->map_size);
	game->tile_size = 0;
	game->window = NULL;
	game->floor = init_image_struct();
	if (!game->floor)
		error(game, "mem alloc of player failed");
	game->player = init_image_struct();
	if (!game->player) // ... || !game->coll, etc...?
		error(game, "mem alloc of player failed");
	game->exit = init_image_struct();
	if (!game->exit)
		error(game, "mem alloc of exit failed");
	game->first_item = init_sprite_elem();
	if (!game->first_item)
		error(game, "mem alloc of list of items failed");
}