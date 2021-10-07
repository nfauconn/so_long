#include "so_long.h"

static void	free_image(t_image *img)
{
	if (img->addr)
		free(img->addr);
	if (img->ptr)
		free(img->ptr);
	if (img->size)
		free(img->size);
	if (img->pos)
		free(img->pos);
	if (img)
		free(img);
}

static void free_sprite_list(t_sprite_elem *list)
{
	t_sprite_elem	*tmp;
	t_sprite_elem	*to_free;

	tmp = list;
	while (tmp != list->prev)
	{
		free_image(tmp->image);
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	free_image(tmp->image);
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
}

void	free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->map)
		free_2d_table(game->map);
	if (game->window)
		free(game->window);
	if (game->map->size)
		free(game->map_size);
	if (game ->screen_res)
		free(game->screen_res);
	if (game->display)
		free(game->display);
	if (game->floor)
		free_image(game->floor);
	if (game->player)
		free_image(game->player);
	if (game->exit)
		free_image(game->exit);
	if (game->first_item)
		free_sprite_list(game->first_item);
	exit(0);
}
