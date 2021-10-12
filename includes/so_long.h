#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define ECHAP 65307
# define UP 65362
# define W 119
# define LEFT 65361
# define A 97
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100
# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define SPRITES_DISPLAY 's'
# define BACKGROUND_DISPLAY 'd'
# define BPP bits_per_pixel
# define PPT px_per_line
# define MISSING_SPRITE "missing sprite in map, minimum = one of each (P, E, C)"
# define BLACK "0xFF000000"

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
	char		type;
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
	int				tile_size;
	t_vector		*map_size;
	t_vector		*screen_res;
	t_image			*background;
	t_image			*sprites;
	t_image			*ground;
	t_image			*wall;
	t_image			*player;
	t_sprite_elem	*first_exit;
	size_t			exit_nb;
	t_sprite_elem	*first_item;
	size_t			item_nb;
}	t_game;

void		adapt_to_tile(t_game *game);
void		check_map(t_game *game, char **map);
int			close_w(t_game *game);
void		color_background(t_image *background);
void		draw_sprites(t_game *game);
void		draw_window(t_game *game);
void		error(t_game *game, char *s);
void		free_game(t_game *game);
int			get_int_color(t_image t, int x, int y);
char		*get_pixel_color(t_image img, int x, int y);
void		get_positions(t_game *game);
int			get_tile_size(t_vector img_size, t_vector res);
void		init_display(t_game *game, t_image *display);
void		init_game_images(t_game *game);
void		init_game_struct(t_game *game);
void		init_image(t_game *game, void *mlx, t_image *img, char *path);
t_image		*init_image_struct(t_game *game, char type);
void		init_screen(t_game *game);
t_vector	*init_vector(t_game *game);
void		init_window(t_game *game, t_vector *screen_res, t_vector *map_size, int *tile_size);
int			key_hooked(int key, t_game *game);
int			make_color_transparent(t_image *tex, char *color);
t_color		new_color(int r, int g, int b, int t);
void		parse_map(t_game *game, char *file);
void		put_pixel_color(t_image *img, int x, int y, char *color);
void		start(t_game *game);
int			update(t_game *game);
t_image		which_background(t_game *game, char tile);
t_image		which_sprite(t_game *game, char tile);
#endif