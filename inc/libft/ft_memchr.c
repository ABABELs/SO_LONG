/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:37:11 by aabel             #+#    #+#             */
/*   Updated: 2022/11/03 10:37:11 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sbis;
	unsigned char	cbis;
	size_t			i;

	sbis = (unsigned char *)s;
	cbis = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (sbis[i] == cbis)
			return ((void *)sbis + i);
		i++;
	}
	return (NULL);
}
