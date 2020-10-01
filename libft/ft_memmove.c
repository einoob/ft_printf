/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:56:27 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:52:29 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destin;
	unsigned char	*source;
	size_t			i;

	destin = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (source < destin)
	{
		while (i++ < len)
			destin[len - i] = source[len - i];
	}
	else
	{
		while (i < len)
		{
			destin[i] = source[i];
			i++;
		}
	}
	return ((void*)destin);
}
