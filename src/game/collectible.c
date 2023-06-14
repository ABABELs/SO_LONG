/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:35:35 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/14 14:54:16 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	collectible(void *param)
{
	t_solong	*sl;
	int			i;
	int			nb_c;

	sl = (t_solong *)param;
	i = 0;
	nb_c = count_spec_c(sl->map->map, 'C');
	check_hitbox_c(sl);
	while (i < count_c(sl->map->map))
	{
		if (nb_c == sl->player->nb_collec
			&& sl->collectible[i]->type == 'E'
			&& sl->collectible[i]->is_collected == -1)
		{
			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
				sl->collectible[i]->x, sl->collectible[i]->y);
			sl->collectible[i]->is_collected = 0;
		}
		i++;
	}
}

int	count_c(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) > 0)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

t_collect	*init_c(t_solong *sl, int x, int y, char type)
{
	t_collect	*collectible;

	collectible = malloc(sizeof(t_collect));
	if (type == 'C')
	{
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[3]);
		collectible->is_collected = 0;
	}
	collectible->x = x * T_S;
	collectible->y = y * T_S;
	if (type == 'E')
	{
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[4]);
		collectible->is_collected = -1;
	}
	collectible->type = type;
	collectible->current_img = 0;
	return (collectible);
}

void	create_c(t_solong *sl)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = 0;
	map = sl->map->map;
	sl->collectible = malloc(sizeof(t_collect *) * (count_c(sl->map->map) + 1));
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) > 0)
			{
				sl->collectible[i] = init_c(sl, x, y, is_c(map[y][x]));
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	sl->collectible[i] = NULL;
}

int	count_spec_c(char **map, char type)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) == type)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}
