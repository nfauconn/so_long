/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfjoinchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:05:07 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/29 13:09:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strfjoinchar(char *str, char c)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	free(str);
	return (new_str);
}
