/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:32:18 by aabel             #+#    #+#             */
/*   Updated: 2023/06/13 12:03:53 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		len1;
// 	int		len2;
// 	char	*str;

// 	if (s1 && s2)
// 	{
// 		len1 = ft_strlen(s1);
// 		len2 = ft_strlen(s2);
// 		str = (char *)malloc(sizeof(*str) * (len1 + len2 + 1));
// 		if (str == NULL)
// 			return (NULL);
// 		i = -1;
// 		while (s1[++i])
// 			str[i] = s1[i];
// 		i = -1;
// 		while (s2[++i])
// 		{
// 			str[len1] = s2[i];
// 			len1++;
// 		}
// 		str[len1] = '\0';
// 		return (str);
// 		freeall(&s1);
// 	}
// 	return (NULL);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*chainjoin;
	size_t	i;
	size_t	u;

	i = -1;
	u = 0;
	if (!s1 || !s2)
		return (0);
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	chainjoin = malloc(sizeof(char) * sizetotal + 1);
	if (!chainjoin)
		return (NULL);
	while (++i < ft_strlen(s1))
		chainjoin[i] = s1[i];
	while (u < ft_strlen(s2))
		chainjoin[i++] = s2[u++];
	chainjoin[i] = '\0';
	return (chainjoin);
}
