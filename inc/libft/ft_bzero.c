/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:29:51 by aabel             #+#    #+#             */
/*   Updated: 2022/11/21 10:56:59 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t c)
{
	unsigned char	*strbis;
	size_t			i;

	strbis = (unsigned char *)str;
	i = 0;
	while (i < c)
	{
		strbis[i] = '\0';
		i++;
	}
	str = (void *)strbis;
}
