/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:31:47 by elindber          #+#    #+#             */
/*   Updated: 2021/05/27 17:39:02 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == a)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
