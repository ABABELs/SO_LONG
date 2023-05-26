/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:42:05 by aabel             #+#    #+#             */
/*   Updated: 2022/11/24 11:10:42 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstbis;
	char			*srcbis;
	size_t			i;

	dstbis = (char *)dst;
	srcbis = (char *)src;
	i = 0;
	if (dstbis == srcbis)
		return (dstbis);
	while (i < n)
	{
		dstbis[i] = srcbis[i];
		i++;
	}
	return (dst);
}
