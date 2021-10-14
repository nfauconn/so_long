/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:53 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 12:04:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && argv[1])
	{
		init_game_struct(&game);
		parse_map(&game, argv[1]);
		init_screen(&game);
		start(&game);
		free_game(&game);
	}
	else
		error(&game, INVALID_NB_ARG);
	return (0);
}
