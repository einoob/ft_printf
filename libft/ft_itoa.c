/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:59:16 by elindber          #+#    #+#             */
/*   Updated: 2021/05/27 17:35:59 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		count;
	long		nbr;
	char		*str;

	nbr = (long)n;
	count = ft_nbrcount((intmax_t)n);
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	count--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	return (str);
}
