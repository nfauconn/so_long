#include "so_long.h"

static void	insert_new_node(t_game *game, int count, t_vector pos)
{
	t_sprite_elem	*new;

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
	new->image = init_image_struct(game);
	new->image->pos->x = pos.x;
	new->image->pos->y = pos.y;
}

static int	get_elem_pos(t_game *game, int letter)
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
				insert_new_node(game, count, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		return (0);
	return (count);
}

static size_t	get_sprite_pos(char **map, t_image *sprite, int letter)
{
	t_vector	pos;
	size_t		count;

	count = 0;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == letter)
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
		return (0);
	return (count);
}

void	get_positions(t_game *game)
{
	size_t	nb_sprites;

	nb_sprites = 0;
	nb_sprites = get_sprite_pos(game->map, game->player, 'P');
	if (nb_sprites == 0)
		error(game, MISSING_SPRITE);
	if (nb_sprites > 1)
		error(game, "found multiple player position in map");
	nb_sprites = get_sprite_pos(game->map, game->exit, 'E');
	if (nb_sprites == 0)
		error(game, MISSING_SPRITE);
	game->item_nb = get_elem_pos(game, 'C');
	if (game->item_nb == 0)
		error(game, MISSING_SPRITE);
}

int	get_pixels_per_tile(t_vector img_size, t_vector res)
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
