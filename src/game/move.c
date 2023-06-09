/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:22:05 by arthurabel        #+#    #+#             */
/*   Updated: 2023/05/31 13:24:33 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move(t_solong *sl)
{
	mlx_t	*mlx;
	int		player_x;
	int		player_y;

	mlx = sl->mlx;
	player_x = sl->player->img->instances[0].x;
	player_y = sl->player->img->instances[0].y;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		go_up(sl, player_x, player_y);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		go_down(sl, player_x, player_y);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		go_left(sl, player_x, player_y);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		go_right(sl, player_x, player_y);
}

void	go_up(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x, player_y - (250 * sl->dt)))
	{
		sl->player->img->instances[0].y -= (250 * sl->dt);
		sl->player->score += (250 * sl->dt);
	}
}

void	go_down(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x, player_y + (250 * sl->dt)))
	{
		sl->player->img->instances[0].y += (250 * sl->dt);
		sl->player->score += (250 * sl->dt);
	}
}

void	go_left(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x - (250 * sl->dt), player_y))
	{
		sl->player->img->instances[0].x -= (250 * sl->dt);
		sl->player->score += (250 * sl->dt);
	}
}

void	go_right(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x + (250 * sl->dt), player_y))
	{
		sl->player->img->instances[0].x += (250 * sl->dt);
		sl->player->score += (250 * sl->dt);
	}
}
