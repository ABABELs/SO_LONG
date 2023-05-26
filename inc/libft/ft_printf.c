/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:12:21 by aabel             #+#    #+#             */
/*   Updated: 2022/12/19 15:34:20 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(va_list ap, const char *input, char c)
{
	(void)input;
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), c, 0));
	else if (c == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		return (ft_putnbr_hexa(va_arg(ap, unsigned long), c, 2));
	}
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ap, int), 0));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	size_t	i;
	int		result;
	va_list	ap;
	int		tmp;

	ft_init(&i, &result);
	va_start(ap, input);
	while (input[++i])
	{
		if (input[i] == '%')
		{
			tmp = ft_check(ap, input, input[++i]);
			if (tmp == -1)
				return (-1);
			result += tmp;
		}
		else
		{
			if (ft_putchar(input[i]) == -1)
				return (-1);
			result++;
		}
	}
	va_end(ap);
	return (result);
}

void	ft_init(size_t *i, int *result)
{
	*i = -1;
	*result = 0;
}
