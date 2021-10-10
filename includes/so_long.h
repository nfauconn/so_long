#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define ECHAP 65307
# define UP 65362
# define W 119
# define LEFT 65364
# define A 97
# define DOWN 65363
# define S 115
# define RIGHT 65361
# define D 100
# define BPP bits_per_pixel
# define CPL size_line
# define PPT px_per_line

# define MISSING_SPRITE "missing sprite in map, minimum = one of each (P, E, C)"

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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_vector	*size;
	t_vector	*pos;
	t_vector	*px_per_tile;
}	t_image;

typedef struct s_sprite_elem
{
	t_image					*image;
	struct s_sprite_elem	*prev;
	struct s_sprite_elem	*next;
} t_sprite_elem;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	void			*window;
	int				pixels_per_tile;
	t_vector		*map_size;
	t_vector		*screen_res;
	t_image			*background;
	t_image			*floor;
	t_image			*wall;
	t_image			*player;
	t_image			*exit;
	t_sprite_elem	*first_item;
	size_t			item_nb;
}	t_game;

void		adapt_to_tile(t_game *game);
void		check_map(t_game *game, char **map);
int			close_w(t_game *game);
void	color_background(t_image *background, t_color color);
void		draw_window(t_game *game);
void		error(t_game *game, char *s);
void		free_game(t_game *game);
int			update(t_game *game);
void		get_positions(t_game *game);
int			get_pixels_per_tile(t_vector img_size, t_vector res);
void		init_game_images(t_game *game);
void		init_image(t_game *game, void *mlx, t_image *img, char *path);
t_image		*init_image_struct(t_game *game);
t_vector	*init_vector(t_game *game);
void		init_window(t_game *game);
void		init_game_struct(t_game *game);
int			key_hooked(int key, t_game *game);
t_color	new_color(int r, int g, int b, int t);
void		parse_map(t_game *game, int argc, char *file);
void		start(t_game *game);

#endif