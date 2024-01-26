/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:06:04 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_game *game, char *s)
{
	ft_putstr_fd("error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		free_game(game);
	exit(0);
}
