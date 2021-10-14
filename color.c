/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:05:43 by user42            #+#    #+#             */
/*   Updated: 2021/10/14 20:10:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_color(t_image *img, int x, int y, char *color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = *(unsigned int *)color;
}

char	*get_pixel_color(t_image img, int x, int y)
{
	char	*color;

	color = img.addr + (y * img.size_line) + (x * (img.bits_per_pixel / 8));
	return (color);
}
