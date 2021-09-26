#include "so_long.h"

void    error(char *s)
{
    ft_printf("error\n");
    ft_printf("%s\n", s);
}

int main()
{
   void    *mlx_pointer;
    
   mlx_pointer = mlx_init();
    if (!mlx_pointer)
        error("failed to initialize mlx");
    if (ft_isdigit('1'))
        ft_putstr_fd("ok\n", 2);
    return (0);
}
