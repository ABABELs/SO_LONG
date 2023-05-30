/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:44:10 by arthurabel        #+#    #+#             */
/*   Updated: 2023/05/30 11:25:02 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define T_S 64

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "G_N_L/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	mlx_image_t	*img;
	int			x;
	int			y;
	char		direction;
	int			height;
	int			width;
	int			timer;
	int			score;
	mlx_image_t	*img_score;
	int			nb_collec;
}			t_player;

typedef struct s_collect
{
	mlx_image_t	*img;
	int			x;
	int			y;
	char		type;
	int			is_collected;
	int			current_img;
}			t_collect;

typedef struct s_map
{
	char	**map;
	int		exit_on;
	int		x;
	int		y;
	int		height;
	int		width;
	int		height_px;
	int		width_px;
}			t_map;

typedef struct s_solong
{
	mlx_t			*mlx;
	mlx_texture_t	**texture;
	t_player		*player;
	t_map			*map;
	t_collect		**collectible;
	int				game_on;
	double			dt;
	double			prev_dt;
}			        t_solong;

char		**parsing(char *map);
t_solong	*init_solong(void);
int			selected_fd(char *map);
char		**add_line(char **array, char *line);
void		print_char_map(char **map);
void		free_texture(t_solong *sl);
void		checking(t_solong *sl);
void		run(t_solong *sl);
void		texture_init(t_solong *sl);
void		init(t_solong *sl);
void		draw_map(t_solong *sl);
void		draw_player(t_solong *sl);
int			check_map(char **map);
void		free_all(t_solong *sl);
void		free_solong(t_solong *sl);
void		free_map(t_solong *sl);
void		delta_time(void *param);
void		ft_hook(void *param);
int			ft_array_len(char **array);
void		key_hook(t_solong *sl);
void		move(t_solong *sl);
int			map_is_rectangle(char **map);
int			player_spawn(char **map);
int			map_is_closed(char **map);
int			map_exit(char **map);
int			check_hitbox(t_solong *sl, int player_x, int player_y);
void		create_c(t_solong *sl);
t_collect	*init_c(t_solong *sl, int x, int y, char type);
int			count_c(char **map);
char		is_c(char type);
void		draw_c(t_solong *sl);
void		collectible(void *param);
void		check_hitbox_c(t_solong *sl);
void		collect(t_solong *sl, int i);
int			count_spec_c(char **map, char type);
int			map_collectible(char **map);
int			coord_is_possible(char **map);
int			**map_in_int(char **map);
void		find_spawn(char **map, int *x, int *y);
int			find_coord(char **map, int **int_map, int i);
int			check_all(char **map, int **int_map);
void		free_int_map(int **int_map, char **map);
int			check_side(int **int_map, int x, int y);
#endif