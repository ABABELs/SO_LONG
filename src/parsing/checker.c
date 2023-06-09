/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:29:32 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/15 12:27:06 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	checking(t_solong *sl)
{
	char	**map;

	map = sl->map->map;
	if (check_map(map) == 0)
		return (0);
	else
	{
		sl->map->width = ft_strlen(map[0]);
		sl->map->height = ft_array_len(map);
		sl->map->height_px = sl->map->height * T_S;
		sl->map->width_px = sl->map->width * T_S;
		return (1);
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
	ft_printf("Error: ");
	if (map_is_rectangle(map) == 0)
		ft_printf("Map is not a rectangle\n");
	else if (player_spawn(map) == 0)
		ft_printf("Map has no player\n");
	else if (map_is_closed(map) == 0)
		ft_printf("Map is not closed\n");
	else if (map_exit(map) == 0)
		ft_printf("Map has no exit\n");
	else if (map_collectible(map) == 0)
		ft_printf("Map has no collectible\n");
	else if (coord_is_possible(map) == 0)
		ft_printf("Map has invalid characters\n");
	return (0);
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
	if (width == height)
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
