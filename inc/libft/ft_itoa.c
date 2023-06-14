/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:38:14 by aabel             #+#    #+#             */
/*   Updated: 2023/06/14 12:15:00 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_convert(char *x, unsigned int num, long int len)
{
	while (num > 0)
	{
		x[len--] = 48 + (num % 10);
		num = num / 10;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*x;
	long int		len;
	unsigned int	num;

	len = ft_len(n);
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
	{
		return (NULL);
	}
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		num = n * -1;
		x[0] = '-';
	}
	else
		num = n;
	x = ft_convert(x, num, len);
	return (x);
}
