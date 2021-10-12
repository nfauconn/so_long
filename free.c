#include "so_long.h"

static void	free_image(t_image *img)
{
	if (img->size)
		free(img->size);
	if (img->pos)
		free(img->pos);
	if (img->px_per_tile)
		free(img->px_per_tile);
	if (img)
		free(img);
}

static void free_sprite_list(t_sprite_elem *first_elem)
{
	t_sprite_elem	*tmp;
	t_sprite_elem	*to_free;

	tmp = first_elem->next;
	while (tmp != first_elem)
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
	if (game->map)
		free_2d_table(game->map);
	if (game->map_size)
		free(game->map_size);
	if (game->screen_res)
		free(game->screen_res);
	if (game->background)
		free_image(game->background);
	if (game->sprites)
		free_image(game->sprites);
	if (game->ground)
		free_image(game->ground);
	if (game->wall)
		free_image(game->wall);
	if (game->player)
		free_image(game->player);
	if (game->first_exit)
		free_sprite_list(game->first_exit);
	if (game->first_item)
		free_sprite_list(game->first_item);
	if (game->mlx)
		free(game->mlx);
}
