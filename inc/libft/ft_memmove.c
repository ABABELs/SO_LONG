/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:55:16 by aabel             #+#    #+#             */
/*   Updated: 2022/11/06 16:38:19 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destbis;
	unsigned char	*srcbis;
	size_t			i;

	destbis = (unsigned char *)dest;
	srcbis = (unsigned char *)src;
	i = -1;
	if (dest == 0 && src == 0)
		return (dest);
	if (dest > src)
	{
		while (++i < n)
			destbis[n - 1 - i] = srcbis[n - 1 - i];
		return (dest);
	}
	while (++i < n)
		destbis[i] = srcbis[i];
	return (dest);
}
