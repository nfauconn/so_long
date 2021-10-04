#include "so_long.h"

t_image	*init_image(void)
{
	t_image	*image;
	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (0);
	image->ptr = NULL;
	image->size.x = 0;
	image->size.y = 0;
	image->pos.x = 0;
	image->pos.y = 0;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
	return (image);
}

static t_sprite_list	*init_sprite_list(void)
{
	t_sprite_list	*list;
	list = (t_sprite_list *)malloc(sizeof(t_sprite_list));
	if (!list)
		return (0);
	list->image = init_image();
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
	game->map_size.x = 0;
	game->map_size.y = 0;
	game->window = NULL;
	game->player = init_image();
	if (!game->player) // ... || !game->coll, etc...?
		error(game, "mem alloc of player failed");
	game->exit = init_image();
	if (!game->exit)
		error(game, "mem alloc of exit failed");
	game->item = init_sprite_list();
	if (!game->item)
		error(game, "mem alloc of list of items failed");
}