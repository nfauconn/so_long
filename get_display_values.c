#include "so_long.h"

static void	insert_new_node(t_game *game, t_sprite_elem *sprite, int count, t_vector pos, char letter)
{
	t_sprite_elem	*new;

/*	if (sprite == ITEM)
	{
		if (count == 1)
		{
			game->first_item->image->pos->x = pos.x;
			game->first_item->image->pos->y = pos.y;
			return ;
		}
		new = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
		if (!new)
			error(game, "malloc error in insert_new_node");
		new->next = game->first_item;
		new->prev = game->first_item->prev;
		game->first_item->prev = new;
		new->prev->next = new;
		new->image = init_image_struct(game, sprite);
		new->image->pos->x = pos.x;
		new->image->pos->y = pos.y;
	}
	if (sprite == EXIT)
	{
*/		if (count == 1)
		{
			sprite->image->pos->x = pos.x;
			sprite->image->pos->y = pos.y;
			return ;
		}
		new = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
		if (!new)
			error(game, "malloc error in insert_new_node");
		new->next = sprite;
		new->prev = sprite->prev;
		sprite->prev = new;
		new->prev->next = new;
		new->image = init_image_struct(game, letter);
		new->image->pos->x = pos.x;
		new->image->pos->y = pos.y;
//	}
}

static void	get_elem_pos(t_game *game, t_sprite_elem *sprite, char letter)
{
	t_vector pos;
	size_t	count;

	count = 0;
	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == letter)
			{
				count++;
				insert_new_node(game, sprite, count, pos, letter);
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		error(game, MISSING_SPRITE);
}

static void	get_sprite_pos(t_game *game, t_image *sprite, int letter)
{
	t_vector	pos;
	size_t		count;

	count = 0;
	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == letter)
			{
				count++;
				sprite->pos->x = pos.x;
				sprite->pos->y = pos.y;
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		error(game, MISSING_SPRITE);
	if (count > 1 && letter == PLAYER)
		error(game, "found multiple player position in map");
}

void	get_positions(t_game *game)
{
	get_sprite_pos(game, game->player, PLAYER);
	get_elem_pos(game, game->first_exit, EXIT);
	get_elem_pos(game, game->first_item, ITEM);
}

int	get_tile_size(t_vector img_size, t_vector res)
{
	t_vector	size;

	size.x = res.x / img_size.x;
	size.y = res.y / img_size.y;
	if (size.x <= size.y)
	{
		if (size.y * img_size.x > res.x)
			size.y = (res.x / img_size.x) - 1;
	}
	else
	{
		if (size.x * img_size.y > res.y)
			size.x = (res.y / img_size.y) - 1;
	}
	if (size.x < size.y)
	{
		if (size.x < 1)
			return (1);
		return (size.x);
	}
	return (size.y);
}
