#include "so_long.h"

static void free_sprite_list(t_sprite_list *list)
{
	t_sprite_list	*tmp;
	t_sprite_list	*to_free;

	tmp = list->next;
	while (tmp != list)
	{
		free(tmp->image);
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	free(tmp->image);
	free(tmp);
}

static void	free_2d_table(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab[y]);
	free(tab);
	tab = NULL;
}

void	free_game(t_game *game)
{
	if (game->map)
		free_2d_table(game->map);
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	if (game->item)
		free_sprite_list(game->item);
	exit(0);
}
