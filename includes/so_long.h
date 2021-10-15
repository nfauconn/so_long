/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:25:51 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 13:16:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define DISPLAY 'd'
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define END 2
# define BLACK 0xFF000000
# define WHITE 0xffffff
# define MISSING_SPRITE "missing sprite in map"
# define INVALID_NB_ARG "invalid number of arg, must be 2 : <pgm> <map>"
# define BER_EXT ".ber"
# define INVALID_FORMAT "invalid format for the map : please use *.ber"
# define INT_MAX_REACHED "number of columns cannot be superior to INT_MAX\n"
# define WRONG_FD "wrong fd or missing correct access rights"
# define MAP_ALLOC_ERR "malloc failure of game->map"
# define EMPTY_LINE "empty line in map / empty map"
# define RECTANGLE_SHAPE "map must be a rectangle"
# define VALID_CHAR "01CEP"
# define INVALID_CHAR "invalid character in map"
# define NOT_CLOSED "map not closed"
# define MULTIPLE_PLAYER "found multiple player position in map"
# define MLX_INIT_FAILED  "start : failed to initialize mlx"

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
	t_v			*size;
	t_v			*pos;
	t_v			*px_per_tile;
	size_t		nb;
}	t_image;

typedef struct s_sprite
{
	t_image				*image;
	struct s_sprite		*prev;
	struct s_sprite		*next;
}	t_sprite;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	void			*window;
	int				tile_size;
	t_v				*map_size;
	t_v				*screen_res;
	t_image			*display;
	t_image			*floor;
	t_image			*wall;
	t_image			*player;
	t_sprite		*first_exit;
	size_t			exit_nb;
	t_sprite		*item;
	size_t			item_nb;
}	t_game;

void		free_sprite_list(t_sprite *first_elem);
void		free_image(t_image *img);
void		adapt_to_tile(t_game *game);
void		check_map(t_game *game, char **map);
int			close_w(t_game *game);
void		draw_tile(t_game *g, t_image *disp, t_image img, t_v map);
void		draw_window(t_game *game);
void		error(t_game *game, char *s);
void		free_game(t_game *game);
int			get_int_color(t_image t, int x, int y);
char		*get_pixel_color(t_image img, int x, int y);
void		get_positions(t_game *game);
int			get_tile_size(t_v img_size, t_v res);
void		init_display(t_game *game, t_image *display);
void		init_game_struct(t_game *game);
void		init_image(t_game *game, void *mlx, t_image *img, char *path);
t_image		*init_image_struct(t_game *game, char type);
void		init_screen(t_game *game);
t_v			*init_vector(t_game *game);
void		init_window(t_game *game, t_v *res, t_v *map_sz, int *tile_size);
int			key_hooked(int key, t_game *game);
int			make_color_transparent(t_image *tex, char *color);
t_color		new_color(int r, int g, int b, int t);
void		parse_map(t_game *game, char *file);
void		put_pixel_color(t_image *img, int x, int y, char *color);
void		start(t_game *game);
int			update(t_game *game);
t_image		which_background(t_game *game, char tile);

#endif