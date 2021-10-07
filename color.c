#include "so_long.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->ptr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}