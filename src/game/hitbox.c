/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:09:43 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/01 13:25:45 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_hitbox(t_solong *sl, int player_x, int player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			if (sl->map->map[y][x] == '1'
			|| (sl->map->map[y][x] == 'W' && sl->collectible != 0))
			{
				if (player_x < (x * T_S + T_S)
					&& (player_x + sl->player->width) > (x * T_S)
					&& player_y < (y * T_S + T_S)
					&& (player_y + sl->player->height) > y * T_S)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	check_hitbox_c(t_solong *sl)
{
	int			i;
	int			nb_c;
	int			player_x;
	int			player_y;

	if (sl->game_on)
	{
		player_x = sl->player->img->instances[0].x;
		player_y = sl->player->img->instances[0].y;
		nb_c = count_c(sl->map->map);
		i = 0;
		while (i < nb_c)
		{
			if (player_x < (sl->collectible[i]->x) + T_S
				&& player_x + sl->player->width > sl->collectible[i]->x
				&& player_y < sl->collectible[i]->y + T_S
				&& player_y + sl->player->height > sl->collectible[i]->y
				&& mlx_is_key_down(sl->mlx, MLX_KEY_E))
			{
				collect(sl, i);
			}
			i++;
		}
	}
}
