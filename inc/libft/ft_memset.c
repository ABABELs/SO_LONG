/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:58:27 by aabel             #+#    #+#             */
/*   Updated: 2022/11/07 16:34:47 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int c, size_t size)
{
	char			*start;
	size_t			i;

	i = 0;
	start = pointer;
	while (i < size)
	{
		start[i] = (unsigned char)c;
		i++;
	}
	return (pointer);
}
