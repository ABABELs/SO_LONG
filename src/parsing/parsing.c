/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:00 by arthurabel        #+#    #+#             */
/*   Updated: 2023/06/15 11:07:44 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	selected_fd(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

char	**add_line(char **array, char *line)
{
	int		i;
	char	**new_array;
	int		len;

	i = 0;
	if (array != NULL)
		while (array[i])
			i++;
	len = i;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		new_array[i] = array[i];
	}
	if (line[ft_strlen(line) - 1] == '\n')
		new_array[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		new_array[i] = ft_strdup(line);
	new_array[++i] = NULL;
	free(array);
	freeall(&line);
	return (new_array);
}

char	**parsing(char *map)
{
	char	**map_tab;
	char	*line;
	int		fd;

	map_tab = NULL;
	fd = selected_fd(map);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map_tab = add_line(map_tab, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_tab);
}
