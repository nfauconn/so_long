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

t_image	*init_image_struct(t_game *game, char type)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		error(game, "mem alloc failed in init_image_struct");
	image->ptr = NULL;
	image->addr = NULL;
	image->BPP = 0;
	image->size_line = 0;
	image->endian = 0;
	image->type = type;
	image->size = init_vector(game);
	image->pos = init_vector(game);
	image->px_per_tile = init_vector(game);
	return (image);
}

static t_sprite_elem	*init_first_sprite_elem(t_game *game, char sprite)
{
	t_sprite_elem	*first_elem;

	first_elem = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
	if (!first_elem)
		error(game, "mem alloc failed in init_sprite_elem");
	first_elem->image = init_image_struct(game, sprite);
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
	game->background = init_image_struct(game, BACKGROUND_DISPLAY);
	game->sprites = init_image_struct(game, SPRITES_DISPLAY);
	game->wall = init_image_struct(game, WALL);
	game->ground = init_image_struct(game, GROUND);
	game->player = init_image_struct(game, PLAYER);
	game->first_exit = init_first_sprite_elem(game, EXIT);
	game->first_item = init_first_sprite_elem(game, ITEM);
	game->item_nb = 0;
	game->exit_nb = 0;
}