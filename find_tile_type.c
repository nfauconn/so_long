#include "so_long.h"

t_image	which_background(t_game *game, char tile)
{
	if (tile == '1')
		return (*game->wall);
	else
		return (*game->ground);
}

t_image	which_sprite(t_game *game, char tile)
{
	static size_t	item_num = 1;
	static size_t	exit_num = 1;

	if (tile == EXIT)
	{
		printf("====> exit n.%zu\n", exit_num);
		if (exit_num > 1 && exit_num <= game->exit_nb)
			game->first_exit = game->first_exit->next;
		exit_num++;
		if (exit_num > game->exit_nb)
		{
			game->first_exit = game->first_exit->next;
			exit_num = 0;
			return (*game->first_exit->prev->image);
		}
		return (*game->first_exit->image);
	}
	if (tile == ITEM)
	{
		printf("====> item n.%zu\n", item_num);
		if (item_num > 1 && item_num <= game->item_nb)
			game->first_item = game->first_item->next;
		item_num++;
		if (item_num > game->item_nb)
		{
			game->first_item = game->first_item->next;
			item_num = 0;
			return (*game->first_item->prev->image);
		}
		return (*game->first_item->image);
	}
	return (*game->player);
}
