#include "so_long.h"

t_image	which_background(t_game *game, char tile)
{
	if (tile == '1')
		return (*game->wall);
	else
		return (*game->ground);
}
