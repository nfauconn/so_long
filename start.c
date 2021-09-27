#include "so_long.h"

void	start(t_var *var)
{
	var->mlx_ptr = mlx_init();
	if (!var->mlx_ptr)
		error("failed to initialize mlx");
	var->window = mlx_new_window(var->mlx_ptr, 1280, 720, "so_long");
	mlx_hook(var->window, 17, 0, close_w, var);
	mlx_key_hook(var->window, key_hooked, var);
}
