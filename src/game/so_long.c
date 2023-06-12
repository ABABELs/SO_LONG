/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:44:27 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/06 14:56:34 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	run(t_solong *sl)
{
	sl->mlx = mlx_init(sl->map->width_px, sl->map->height_px, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	init(sl);
	mlx_loop_hook(sl->mlx, collectible, sl);
	// mlx_loop_hook(sl->mlx, water_door, sl);
	mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop_hook(sl->mlx, delta_time, sl);
	mlx_loop(sl->mlx);
	free_all(sl);
	mlx_terminate(sl->mlx);
	free(sl);
}

void	ft_hook(void *param)
{
	t_solong	*sl;
	char		*str;

	sl = (t_solong *)param;
	str = ft_strjoin(" Move : ", ft_itoa(sl->player->score));
	ft_printf("%s\n", str);
	if (sl->game_on)
		move(sl);
	if (sl->player->img_score == NULL)
		sl->player->img_score = mlx_put_string(sl->mlx, str, 0, 0);
	else
	{
		mlx_delete_image(sl->mlx, sl->player->img_score);
		sl->player->img_score = mlx_put_string(sl->mlx, str, 0, 0);
		mlx_resize_image(sl->player->img_score, 200, 40);
		free(str);
	}
	key_hook(sl);
}

void	delta_time(void *param)
{
	t_solong	*sl;
	double		current_time;

	sl = (t_solong *)param;
	current_time = mlx_get_time();
	sl->dt = current_time - sl->prev_dt;
	sl->prev_dt = current_time;
}

void	init(t_solong *sl)
{
	draw_map(sl);
	draw_player(sl);
	create_c(sl);
	draw_c(sl);
}

int	main(int argc, char **argv)
{
	t_solong	*solong;

	if (argc != 2)
		exit(1);
	solong = init_solong();
	solong->map->map = parsing(argv[1]);
	if (solong->map->map == NULL)
	{
		free(solong->map);
		free(solong->player);
		free_texture(solong);
		free(solong);
		exit(1);
	}
	print_char_map(solong->map->map);
	checking(solong);
	run(solong);
	return (0);
}
