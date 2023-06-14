/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:42:27 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/14 15:00:45 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_solong	*init_solong(void)
{
	t_solong	*sl;

	sl = malloc(sizeof(t_solong));
	sl->map = malloc(sizeof(t_map));
	sl->player = malloc(sizeof(t_player));
	sl->mlx = NULL;
	sl->texture = NULL;
	sl->player->height = 55;
	sl->player->width = 64;
	sl->game_on = 1;
	sl->prev_dt = 0;
	sl->dt = 0;
	sl->player->timer = 0;
	sl->player->score = 0;
	sl->player->nb_collec = 0;
	texture_init(sl);
	return (sl);
}

void	texture_init(t_solong *sl)
{
	sl->texture = malloc(sizeof(mlx_texture_t *) * 5);
	sl->texture[0] = mlx_load_png("./images/character_2.png");
	sl->texture[1] = mlx_load_png("./images/wall.png");
	sl->texture[2] = mlx_load_png("./images/move_zone.png");
	sl->texture[3] = mlx_load_png("./images/key.png");
	sl->texture[4] = mlx_load_png("./images/end_door.png");
	sl->texture[5] = NULL;
}
