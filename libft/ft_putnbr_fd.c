/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:46:30 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:52:52 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long k;

	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k = k * -1;
	}
	if (k / 10 > 0)
	{
		ft_putnbr_fd(k / 10, fd);
	}
	ft_putchar_fd('0' + k % 10, fd);
}
