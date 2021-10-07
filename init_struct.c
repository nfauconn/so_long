#include "so_long.h"

void	init_vector(t_vector *vector)
{
	vector->x = 0;
	vector->y = 0;
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
	init_vector(&image->size);
	init_vector(&image->pos);
	return (image);
}

static t_sprite_elem	*init_first_sprite_elem(t_game *game)
{
	t_sprite_elem	*list;
	list = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
	if (!list)
		error(game, "mem alloc failed in init_sprite_elem");
	list->image = init_image_struct(game);
	list->prev = list;
	list->next = list;
	return (list);
}

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->window = NULL;
	game->tile_size = 0;
	init_vector(&game->map_size);
	init_vector(&game->screen_res);
	game->floor = init_image_struct(game);
	game->player = init_image_struct(game);
	game->exit = init_image_struct(game);
	game->first_item = init_first_sprite_elem(game);
}