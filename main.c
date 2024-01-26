/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:53 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by nfauconn         ###   ########.fr       */
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
