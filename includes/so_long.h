#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define ECHAP 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

# define MISSING_SPRITE "missing sprite in map, minimum = one of each (P, E, C)"

typedef enum e_sprites
{
	P = 0,
	C,
	E
}	t_sprites;

typedef enum e_bool
{
	SUCCESS = 1,
	FAILURE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;


typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	t_vector	pos;
	char		*addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_sprite_list
{
	t_image					*image;
	struct s_sprite_list	*prev;
	struct s_sprite_list	*next;
} t_sprite_list;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	t_vector		map_size;
	void			*window;
	t_image			*player;
	t_image			*exit;
	t_sprite_list	*item;
}	t_game;

void		check_map(t_game *game, char **map);
int			close_w(t_game *game);
void		error(t_game *game, char *s);
void		free_game(t_game *game);
int			ft_update(t_game *game);
t_image		*init_image(void);
void		get_positions(t_game *game);
void		init_game_struct(t_game *game);
int			key_hooked(t_game *game, int keycode);
void		parse_map(t_game *game, int argc, char *file);
void		start(t_game *game);

#endif