/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:58:22 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/29 13:09:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_nb(char const *s, char c)
{
	int	i;
	int	str_nb;

	i = 0;
	while (s[i] && (s[i] == c))
		i++;
	str_nb = 0;
	while (s[i])
	{
		while (s[i] && (s[i] != c))
			i++;
		str_nb++;
		while (s[i] && (s[i] == c))
			i++;
	}
	return (str_nb);
}

static int	str_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	tab = (char **)malloc(sizeof (char *) * (str_nb(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (s[i] && (index < str_nb(s, c)))
	{
		while (s[i] == c)
			i++;
		tab[index] = malloc(sizeof (char) * (str_len(s + i, c) + 1));
		if (!tab[index])
			return (NULL);
		j = 0;
		while (s[i] && s[i] != c)
			tab[index][j++] = s[i++];
		tab[index][j] = '\0';
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
