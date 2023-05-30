/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:41 by aabel             #+#    #+#             */
/*   Updated: 2023/05/30 11:37:27 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlens(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl( char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int j, int i)
{
	char	*dest;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlens(s1) + ft_strlens(s2) + 1));
	if (!dest)
	{
		free(s1);
		return (ft_lstfree(&dest));
	}
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	ft_lstfree(&s1);
	return (dest);
}

void	ft_bzero_gnl(void *str, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)str;
	i = 0;
	while (i < len)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero_gnl(str, (count * size));
	return (str);
}
