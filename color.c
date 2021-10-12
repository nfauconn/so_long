#include "so_long.h"

void	put_pixel_color(t_image *img, int x, int y, char *color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->BPP / 8));
	*(unsigned int*)dst = *(unsigned int*)color;
}

char	*get_pixel_color(t_image img, int x, int y)
{
	char	*color;

	color = img.addr + (y * img.size_line) + (x * (img.BPP / 8));
	return (color);
}

int	get_int_color(t_image t, int x, int y)
{
	int	color;
	int	*int_addr;

	int_addr = (int *)t.addr;
	color = int_addr[y * t.size->x + (x * t.size->x)];
	return (color);
}

int	make_color_transparent(t_image *tex, char *color)
{
	int		transparancy;
	int		actual;
	int		background;

	background = 0xFFFFFF;
	if (!tex)
		return (background);
	transparancy = get_int_color(*tex, 0, 0);
	actual = *(int *)color;
	if (actual == transparancy)
		return (background);
	else
		return (actual);
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

void	color_background(t_image *background)
{
	int			x;
	int			y;
	int			char_per_px;
	int			color;

	y = 0;
	char_per_px = background->BPP / 8;
	color = 0x00FFFFFF;
	while (y < background->size->y)
	{
		x = 0;
		while (x < background->size->x)
		{
			background->addr[(x * char_per_px + background->size_line * y) + 0] = color;
			background->addr[(x * char_per_px + background->size_line * y) + 1] = color;
			background->addr[(x * char_per_px + background->size_line * y) + 2] = color;
			background->addr[(x * char_per_px + background->size_line * y) + 3] = color;
			x++;
		}
		y++;
	}
}