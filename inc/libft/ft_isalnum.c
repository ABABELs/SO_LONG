/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:13:15 by aabel             #+#    #+#             */
/*   Updated: 2022/11/01 12:23:21 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c <= 122) && (c >= 97))
		|| ((c <= 90) && (c >= 65)))
		return (1);
	else if ((c <= 57) && (c >= 48))
		return (1);
	else
		return (0);
}
