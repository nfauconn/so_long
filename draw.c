#include "so_long.h"

t_image	*which_texture(t_game *game, char tile)
{
	static size_t	item_num = 1;

	if (tile == '0')
		return (game->floor);
	if (tile == '1')
		return (game->wall);
	if (tile == 'P')
		return (game->player);
	if (tile == 'E')
		return (game->exit);
	if (tile == 'C')
	{
		if (item_num > 1 && item_num <= game->item_nb)
			game->first_item = game->first_item->next;
		item_num++;
		if (item_num > game->item_nb)
		{
			game->first_item = game->first_item->next;
			return (game->first_item->prev->image);
		}
		return (game->first_item->image);
	}
	return (0);
}
/*
void	draw_tile(t_game *game, t_image img, int x, int y)
{			
	int		px_per_tile;
	int		width;
	int		height;
	int		color;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			px_per_tile = get_pixels_per_tile(img.size, )
			color = *(img.addr + (y * img.CPL + (x * (img.BPP / 8))));
			img.p_data_y = startY + img.y;
			img.p_data_x = startX + img.x;
			if (color != (int)BLACK)
				set_pixel(img, img.p_data_y, img.p_data_x, color);
			img.x++;
		}
		img.y++;
	}
}
*/
void	draw_window(t_game *game)
{
	t_image	*img;
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_printf("texture case(%d,%d) = %c", x, y, game->map[y][x]);
			img = which_texture(game, game->map[y][x]);
			//draw_tile(game, img, x, y);
			x++;
		}
		y++;
	}
}