/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:55:36 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:53:47 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	x;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	x = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (src[x] != '\0' && x < dstsize - dlen - 1)
	{
		dst[dlen + x] = src[x];
		x++;
	}
	dst[dlen + x] = '\0';
	return (dlen + slen);
}
