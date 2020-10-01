/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:05:21 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:54:32 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (needle[t] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		t = 0;
		while (haystack[i + t] == needle[t])
		{
			t++;
			if (needle[t] == '\0')
				return ((char*)haystack + (i));
		}
		i++;
	}
	return (NULL);
}
