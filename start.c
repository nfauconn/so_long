#include "so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr  = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size, &img.endian);
/*	img.ratio = img.size.y / img.size.x;
	img.size.x /= 2;
	img.size.y /= (2 * img.ratio);
	img.addr  = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size, &img.endian);
*/	return (img);
}

void	start(t_var *var)
{
	var->mlx_ptr = mlx_init();
	if (!var->mlx_ptr)
		error("failed to initialize mlx");
	var->window = mlx_new_window(var->mlx_ptr, 1280, 720, "so_long");
	
	var->sprite = ft_new_sprite(var->mlx_ptr, "./puck.xpm");
	var->sprite_position.x = 0;
	var->sprite_position.y = 0;
	mlx_put_image_to_window(var->mlx_ptr, var->window, var->sprite.ptr, var->sprite_position.x, var->sprite_position.y);
	mlx_hook(var->window, 17, 0, close_w, var);
	mlx_key_hook(var->window, *key_hooked, var);
	mlx_loop_hook(var->mlx_ptr, *ft_update, var);
}
