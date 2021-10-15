/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:53 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 11:52:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !argv[1])
	{
		ft_putstr_fd(INVALID_NB_ARG, 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}	
	init_game_struct(&game);
	parse_map(&game, argv[1]);
	init_screen(&game);
	start(&game);
	free_game(&game);
	return (0);
}
