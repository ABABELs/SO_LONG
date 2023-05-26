/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:35:15 by aabel             #+#    #+#             */
/*   Updated: 2023/05/22 12:55:02 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lstfree(char **buffer)
{
	free(*buffer);
	*buffer = 0;
	return (*buffer);
}

char	*ft_savenext(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		ft_lstfree(&buffer);
		return (NULL);
	}
	line = ft_calloc_gnl(sizeof(char), ft_strlens(buffer) - i);
	if (!line)
	{
		ft_lstfree(&buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	ft_lstfree(&buffer);
	return (line);
}

char	*ft_oneline(char *buffer)

{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc_gnl(sizeof(char), i + 2);
	else
		line = ft_calloc_gnl(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*read_file(int fd, char *buffer_static, char *buffer)
{
	ssize_t		byte_len;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (ft_lstfree(&buffer_static));
	byte_len = 1;
	while (byte_len > 0 && !ft_strchr_gnl(buffer_static, '\n'))
	{
		byte_len = read(fd, buffer, BUFFER_SIZE);
		if (byte_len == -1)
		{
			ft_lstfree(&buffer);
			ft_lstfree(&buffer_static);
			return (NULL);
		}
		buffer[byte_len] = '\0';
		if (byte_len > 0)
		{
			buffer_static = ft_strjoin_gnl(buffer_static, buffer, 0, -1);
			if (!buffer_static)
				return (buffer = ft_lstfree(&buffer));
		}
	}
	ft_lstfree(&buffer);
	return (buffer_static);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buffer = ft_lstfree(&buffer));
	buffer = read_file(fd, buffer, 0);
	if (!buffer)
		return (NULL);
	line = ft_oneline(buffer);
	if (!line)
		return (buffer = ft_lstfree(&buffer));
	buffer = ft_savenext(buffer);
	return (line);
}

// int	main(void)
// {
	// int		fd;
	// char	*result;
	// fd = open("exemple.txt", O_RDONLY);
	// result = get_next_line(fd);
	// printf("0%s", result);
	//  result = get_next_line(fd);
	//  printf("1%s", result);
	//  result = get_next_line(fd);
	//  printf("2%s", result);
	//  result = get_next_line(fd);
	//  printf("3%s", result);
	//  result = get_next_line(fd);
	//  printf("4%s", result);
	//  result = get_next_line(fd);
	//  printf("5%s", result);
	//  result = get_next_line(fd);
	//  printf("6%s", result);
	//  result = get_next_line(fd);
	//  printf("7%s", result);
	//  result = get_next_line(fd);
	//  printf("8%s", result);
	// return (0);
// }
