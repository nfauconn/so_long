#include "so_long.h"

int	close_w(t_var *var)
{
	mlx_destroy_window(var->mlx_ptr, (void *)var->window);
	exit(0);
	return (0);
}

int	key_hooked(int key, t_var *var)
{
	ft_printf("keycode = %d\n", key);
	if (key == ECHAP)
		close_w(var);
	else if (key == UP)
		var->sprite_position.y += var->sprite.size.y;
	else if (key == LEFT)
		var->sprite_position.x -= var->sprite.size.x;
	else if (key == DOWN)
		var->sprite_position.y += var->sprite.size.y;
	else if (key == RIGHT)
		var->sprite_position.x += var->sprite.size.x;
	mlx_put_image_to_window(var->mlx_ptr, var->window, var->sprite.ptr, var->sprite_position.x, var->sprite_position.y);
	return (0);
}

int	ft_update(t_var *var)
{
	static int	frame;

	frame++;
	if (frame == 200)
		var->sprite_position.y += 1;
	else if (frame >= 200 * 2)
	{
		var->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(var->mlx_ptr, var->window, var->sprite.ptr, var->sprite_position.x, var->sprite_position.y);
	return (0);
}
