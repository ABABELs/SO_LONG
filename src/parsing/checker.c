/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:29:32 by arthurabel        #+#    #+#             */
/*   Updated: 2023/05/30 13:11:30 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	checking(t_solong *sl)
{
	char	**map;

	map = sl->map->map;
	if (check_map(map) == 0)
		printf("Error\n");
    else
	{
		sl->map->width = ft_strlen(map[0]);
		sl->map->height = ft_array_len(map);
		sl->map->height_px = sl->map->height * T_S;
		sl->map->width_px = sl->map->width * T_S;
	}
}

int	check_map(char **map)
{
	if (map_is_rectangle(map) == 1)
		if (player_spawn(map) == 1)
			if (map_is_closed(map) == 1)
				if (map_exit(map) == 1)
					if (map_collectible(map) == 1)
						if (coord_is_possible(map) == 1)
							return (1);
	return (0);
	if (map)
		return (1);
}

int	map_is_rectangle(char **map)
{
	int	i;
	int	height;
	int	width;

	height = ft_array_len(map);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlens(map[i]) != width)
			return (0);
		i++;
	}
	if (width < height)
		return (0);
	return (1);
}

int	player_spawn(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	map_is_closed(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	j = 0;
	height = ft_array_len(map);
	width = ft_strlen(map[0]);
	while (map[i])
	{
		while (map[i][j])
		{
			if (i == 0 || i == height - 1)
				if (map[i][j] != '1')
					return (0);
			if (j == 0 || j == width - 1)
				if (map[i][j] != '1')
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}