/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:35:47 by aabel             #+#    #+#             */
/*   Updated: 2023/05/30 11:36:59 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s, int c);
void	*ft_calloc_gnl(size_t count, size_t size);
int		ft_strlens(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2, int j, int i);
char	*read_file(int fd, char *buffer_static, char *buffer);
char	*ft_oneline(char *buffer);
char	*ft_savenext(char *buffer);
char	*ft_lstfree(char **buffer);
void	ft_bzero_gnl(void *str, size_t len);

#endif
