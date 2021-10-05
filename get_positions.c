#include "so_long.h"

static void	insert_new_node(t_game *game, int count, int letter, t_vector pos)
{
	t_sprite_elem	**last;
	t_sprite_elem	*new;

	if (letter == 'C')
		last = &game->first_item;
	if (count == 1)
	{
		(*last)->image->pos = pos;
		return ;
	}
	new = (t_sprite_elem *)malloc(sizeof(t_sprite_elem));
	if (!new)
		error(game, "malloc error in insert_new_node");
	new->next = (*last);
	new->prev = (*last)->prev;
	(*last)->prev = new;
	new->prev->next = new;
	new->image = init_image_struct();
	new->image->pos = pos;
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
				insert_new_node(game, count, letter, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
	if (count == 0)
		return (0);
	return (count);
}

static int	get_sprite_pos(char **map, t_image *sprite, int letter)
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
				sprite->pos = pos;
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
	int	nb_sprites;

	nb_sprites = 0;
	nb_sprites = get_sprite_pos(game->map, game->player, 'P');
	if (nb_sprites == 0)
		error(game, MISSING_SPRITE);
	if (nb_sprites > 1)
		error(game, "found multiple player position in map");
	nb_sprites = get_sprite_pos(game->map, game->exit, 'E');
	if (nb_sprites == 0)
		error(game, MISSING_SPRITE);
	nb_sprites = get_elem_pos(game, 'C');
	
	ft_printf("player_pos = %d, %d\n", game->player->pos.x, game->player->pos.y);
	ft_printf("exit_pos = %d, %d\n", game->exit->pos.x, game->exit->pos.y);

	t_sprite_elem *tmp;
	tmp = game->first_item;
	while (tmp->next != game->first_item)
	{
		ft_printf("item_pos = %d, %d\n", tmp->image->pos.x, tmp->image->pos.y);
		tmp = tmp->next;
	}
	ft_printf("item_pos = %d, %d\n", tmp->image->pos.x, tmp->image->pos.y);
}
