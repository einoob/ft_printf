/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:00:48 by elindber          #+#    #+#             */
/*   Updated: 2020/10/06 18:40:16 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_identifiers
{
	const char	*format;
	char		*flag;
	size_t		minwth;
	size_t		period;
	size_t		maxwth;
	size_t		i;
	size_t		printed_chars;
	size_t		double_len;
	int			negative;
	char		*arg_type;
	char		*modifiers;
	char		current_flag[6];
	char		current_type;
	char		current_modifier[3];
	va_list		arguments;
}				t_tags;

void			scan_flags(t_tags *ids);
void			scan_minwth(t_tags *ids);
void			scan_period_maxwth(t_tags *ids);
void			scan_modifier(t_tags *ids);
void			scan_arg_type(t_tags *ids);
void			create_tmp_ids(t_tags *ids);
void			print_c(t_tags *ids);
void			print_d(t_tags *ids);
void			print_s(t_tags *ids);
void			print_p(t_tags *ids);
void			print_o(t_tags *ids);
void			print_u(t_tags *ids);
void			print_x(t_tags *ids);
void			print_f(t_tags *ids);
void			print_percent(t_tags *ids);
void			put_zero_oxu(t_tags *ids, size_t len);
void			put_zero_df(t_tags *ids, size_t len);
void			put_zero_p(t_tags *ids, size_t len);
void			put_plusminus(t_tags *ids, intmax_t nbr);
void			minwth_print(t_tags *ids, size_t len);
void			period_zero(t_tags *ids);
int				ft_printf(const char *format, ...);
int				read_format(t_tags *ids);
intmax_t		cast_number(t_tags *ids, intmax_t nbr);
uintmax_t		cast_unsigned_number(t_tags *ids, uintmax_t nbr);
long double		cast_double(t_tags *ids, long double nbr);
intmax_t		base_nbrcount(intmax_t n, size_t base);
intmax_t		unsigned_base_nbrcount(uintmax_t n, size_t base);
char			*imaxtoa_base(intmax_t nbr, size_t base);
char			*uimaxtoa_base(uintmax_t nbr, size_t base);
char			*uimaxtoa_base_capital(uintmax_t nbr, size_t base);
#endif
