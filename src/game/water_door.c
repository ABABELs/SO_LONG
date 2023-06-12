/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:29:22 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/12 13:27:59 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// void	water_door(void *param)
// {
// 	t_solong	*sl;
// 	int			i;
// 	int			nb_c;

// 	sl = (t_solong *)param;
// 	i = 0;
// 	nb_c = count_spec_c(sl->map->map, 'C');
// 	while (i < count_c(sl->map->map))
// 	{
// 		if (nb_c < sl->player->nb_collec && sl->collectible[i]->type == 'W')
// 		{
// 			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
// 				sl->collectible[i]->x, sl->collectible[i]->y);
// 		}
// 		else if (nb_c == sl->player->nb_collec
// 			&& sl->collectible[i]->type == 'W')
// 		{
// 			change_w_to_0(sl);
// 			mlx_delete_image(sl->mlx, sl->collectible[i]->img);
// 		}
// 		i++;
// 	}
// }

// void	change_w_to_0(t_solong *sl)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (sl->map->map[i])
// 	{
// 		while (sl->map->map[i][j])
// 		{
// 			if (sl->map->map[i][j] == 'W')
// 				sl->map->map[i][j] = '0';
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }
