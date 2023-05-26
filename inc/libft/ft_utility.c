/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:51:50 by aabel             #+#    #+#             */
/*   Updated: 2022/12/19 15:34:14 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long n, int init)
{
	static int	i;

	i = init;
	if (n < 0 && i != -1)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		n = n * -1;
	}
	if (n > 9)
		if (ft_putnbr((n / 10), i) == -1)
			return (-1);
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putnbr_u(unsigned int n, int init)
{
	static int	i;

	i = init;
	if (n > 9)
		if (ft_putnbr_u((n / 10), i) == -1)
			return (-1);
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	i++;
	return (i);
}
