#include "so_long.h"

int	close_w(t_var *var)
{
	mlx_destroy_window(var->mlx_ptr, (void *)var->window);
	exit(0);
	return (0);
}

int	key_hooked(int	keycode, t_var *var)
{
	if (keycode == ECHAP)
		close_w(var);
	return (0);
}
