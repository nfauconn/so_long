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
