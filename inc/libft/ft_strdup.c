/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:57 by aabel             #+#    #+#             */
/*   Updated: 2022/11/06 16:03:08 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*bis;
	int		i;

	bis = malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (!bis)
		return (NULL);
	i = 0;
	while (source[i])
	{
		bis[i] = source[i];
		i++;
	}
	bis[i] = 0;
	return (bis);
}
