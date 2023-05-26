/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:39 by arthurabel        #+#    #+#             */
/*   Updated: 2023/05/24 14:12:23 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_map(t_solong *sl)
{
	mlx_image_t	*img;
	mlx_image_t	*imgsol;
	int			x;
	int			y;

	imgsol = mlx_texture_to_image(sl->mlx, sl->texture[4]);
	img = mlx_texture_to_image(sl->mlx, sl->texture[3]);
	x = 0;
	y = 0;
	while (sl->map->map[y] > 0)
	{
		while (sl->map->map[y][x] > 0)
		{
			mlx_image_to_window(sl->mlx, imgsol, (x * T_S), (y * T_S));
			if (sl->map->map[y][x] == '1')
				mlx_image_to_window(sl->mlx, img, (x * T_S), (y * T_S));
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_player(t_solong *sl)
{
	char		**map;
	int			x;
	int			y;

	sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[1]);
	map = sl->map->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				mlx_image_to_window(sl->mlx, sl->player->img, x * T_S, y * T_S);
			x++;
		}
		x = 0;
		y++;
	}
}
