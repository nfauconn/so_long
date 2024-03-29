/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:53:24 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_percent(va_list *ap, t_conv *conv)
{
	(void)ap;
	if (conv->is_width && conv->width > 1)
	{
		conv->len = conv->width;
		conv->str = ft_memalloc(conv->len + 1);
		if (conv->zero_padded && !conv->left)
			ft_memset(conv->str, '0', conv->len);
		else
			ft_memset(conv->str, ' ', conv->len);
		if (conv->left)
			conv->str[0] = '%';
		else
			conv->str[conv->len - 1] = '%';
	}
	else
	{
		conv->len = 1;
		conv->str = ft_memalloc(2);
		conv->str[0] = '%';
	}
}
