/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:24:18 by arthurabel        #+#    #+#             */
/*   Updated: 2023/05/23 16:33:21 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_texture(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->texture[i] && sl->texture)
	{
		if (sl->texture[i])
			mlx_delete_texture(sl->texture[i]);
		i++;
	}
	free(sl->texture);
}

void	free_all(t_solong *sl)
{
	free_solong(sl);
	free_texture(sl);
}

void	free_solong(t_solong *sl)
{
	free_map(sl);
	if (sl->player->img)
		mlx_delete_image(sl->mlx, sl->player->img);
	if (sl->player->img_score)
		mlx_delete_image(sl->mlx, sl->player->img_score);
	free(sl->player);
}

void	free_map(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->map->map[i])
	{
		free(sl->map->map[i]);
		i++;
	}
	free(sl->map->map);
	free(sl->map);
}
