#include "so_long.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->ptr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

t_color	new_color(int r, int g, int b, int t)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.t = (char)t;
	return (color);
}

void	color_background(t_image *background, t_color color)
{
	int	x;
	int	y;

	background->addr = mlx_get_data_addr(background->ptr, &background->bpp, &background->line_size, &background->endian);
	y = 0;
	while (y < background->size->y)
	{
		x = 0;
		while (x < background->size->x)
		{
			background->addr[(x * 4 + background->line_size * y) + 0] = color.b;
			background->addr[(x * 4 + background->line_size * y) + 1] = color.g;
			background->addr[(x * 4 + background->line_size * y) + 2] = color.r;
			background->addr[(x * 4 + background->line_size * y) + 3] = color.t;
			x++;
		}
		y++;
	}
}