/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:59:17 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert(va_list *ap, t_pf *pf)
{
	t_conv	conv;

	init_conv(&conv);
	parse_flag(pf, &conv, ap);
	if (parse_conv(pf) != -1)
	{
		pf->fun_ptr[pf->index_conv](ap, &conv);
		insert_into_buffer(pf, conv.str, conv.len);
		free(conv.str);
		conv.str = NULL;
	}
}
