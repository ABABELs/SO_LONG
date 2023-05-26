/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:24:40 by aabel             #+#    #+#             */
/*   Updated: 2022/12/19 15:40:54 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return (NULL);
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
	return (NULL);
}

static size_t	ft_sizetab(char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (!s || !s[i])
		return (word);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while ((s[i] && s[i] == c))
				i++;
		}
		else
			i++;
	}
	if ((i - 1 >= 0) && (s[i - 1] != c))
	word++;
	return (word);
}

static char	*ft_word(const char *str, char c)
{
	char	*word;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[j] != c && str[j])
		j++;
	word = malloc((j + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (++i < j)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		j;
	int		i;

	j = -1;
	if (!s)
		return (0);
	i = ft_sizetab((char *)s, c);
	tab = ft_calloc(sizeof(char *), (i + 1));
	if (!tab)
		return (NULL);
	while (++j <= i)
	{
		while (s[0] == c && s[0])
			s++;
		if (s[0] != c && s[0])
		{
			tab[j] = ft_word(s, c);
			if (!tab[j])
				return (ft_free(tab));
			s += ft_strlen(tab[j]);
		}
	}
	return (tab);
}

// int	main()
// {
// 	char tab[] = "coucou toi belle homme";
// 	char	c = 'o';
// 	int	i = 0;
// 	char **result;

// 	result = ft_split(tab, c);
// 	while (i < 2)
// 			ft_printf("%s", result[i++]);
// 	return (0);
// }
