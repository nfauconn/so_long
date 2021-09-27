#include "so_long.h"

int main()
{
	t_var	var;

	start(&var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
