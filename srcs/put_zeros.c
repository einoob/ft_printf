/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:55:31 by elindber          #+#    #+#             */
/*   Updated: 2020/10/06 18:39:14 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_zero(t_tags *ids, size_t len)
{
	if (ids->period == 1 && ids->current_type != 'f')
	{
		while (ids->maxwth > len)
		{
			write(1, "0", 1);
			ids->printed_chars++;
			ids->minwth--;
			len++;
		}
		return ;
	}
	while (ids->minwth > len)
	{
		write(1, "0", 1);
		ids->printed_chars++;
		len++;
	}
}

static void	maxwth_write(t_tags *ids, size_t len)
{
	while (ids->maxwth > len)
	{
		if (ids->minwth == 0)
			ids->minwth++;
		write(1, "0", 1);
		ids->minwth--;
		len++;
		ids->printed_chars++;
	}
}

void		put_zero_df(t_tags *ids, size_t len)
{
	if (ids->current_type == 'f')
		len += ids->period == 0 ? 7 : ids->maxwth + 1;
	if (ids->current_flag[4] == '-' && ids->minwth > len && ids->period == 0)
		return ;
	if (ids->current_flag[3] == '+' && ids->period == 0 && ids->negative == 1)
		len++;
	if (ids->current_flag[1] == '0' && ids->current_flag[2] == ' ' &&
	ids->minwth > len && ids->negative == 1)
		len++;
	if (ids->negative == -1 && ids->maxwth + 1 > len)
		len--;
	write_zero(ids, len);
}

void		put_zero_p(t_tags *ids, size_t len)
{
	if (ids->current_flag[1] == '0' && ids->period == 1 && ids->maxwth < len)
		return ;
	else if (ids->current_type == 'p' && ids->current_flag[1] == '0'
	&& ids->period == 0)
		len += 2;
	if (ids->maxwth >= len)
	{
		maxwth_write(ids, len);
		return ;
	}
	while (ids->minwth > len)
	{
		write(1, "0", 1);
		len++;
		ids->printed_chars++;
	}
}

void		put_zero_oxu(t_tags *ids, size_t len)
{
	if (ids->current_type == 'u' && ids->current_flag[1] == '0'
	&& ids->period == 1 && ids->maxwth < len)
		return ;
	if ((ids->current_type == 'o' || ids->current_type == 'x'
	|| ids->current_type == 'X') && ((ids->current_flag[1] == '0'
	&& ids->period == 1 && ids->maxwth < len)
	|| (ids->current_flag[4] == '-' && ids->minwth > len && ids->period == 0)))
		return ;
	if ((ids->current_type == 'x' || ids->current_type == 'X')
	&& ids->current_flag[0] == '#' && ids->maxwth <= len)
		len += 2;
	if (ids->maxwth >= len)
	{
		maxwth_write(ids, len);
		return ;
	}
	while (ids->minwth > len)
	{
		write(1, "0", 1);
		len++;
		ids->printed_chars++;
	}
}
