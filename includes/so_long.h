#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

# define ECHAP 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

typedef enum e_bool
{
	SUCCESS = 1,
	FAILURE = 0
}	t_bool;

typedef struct	s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct	s_window
{
	void		*ptr;
	t_vector	size;
}	t_window;

typedef struct s_color
{
	int	r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct	s_image
{
	void      *ptr;
	t_vector  size;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

typedef struct  s_variables
{
	void		*mlx_ptr;
	void		*window;
	t_image		sprite;
	t_vector	sprite_position;
}	t_var;

int			close_w(t_var *var);
void		error(char *s);
int			key_hooked(int	keycode, t_var *var);
void		start(t_var *var);

#endif