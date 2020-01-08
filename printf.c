/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:05:34 by rzafari           #+#    #+#             */
/*   Updated: 2020/01/08 14:51:45 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_apply_flags(t_flags *flags)
{
	if (flags->type == 'c')
		if (!(ft_type_c(flags)))
			return (0);
	if (flags->type == 's')
		if (!(ft_type_s(flags)))
			return (0);
	if (flags->type == 'd')
		if (!(ft_type_i(flags)))
			return (0);
	if (flags->type == 'p')
		if (!(ft_type_p(flags)))
			return (0);
	if (flags->type == 'i')
		if (!(ft_type_i(flags)))
			return (0);
	if (flags->type == 'u')
		if (!(ft_type_u(flags)))
			return (0);
	if (flags->type == 'x')
		if (!(ft_type_x(flags, 0)))
			return (0);
	if (flags->type == 'X')
		if (!(ft_type_x(flags, 1)))
			return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;
	int		i;
	char	**str;

	flags.tot = 0;
	ft_initializeflags(&flags);
	flags.tot = 0;
	va_start(flags.ap, format);
	if ((i = ft_search_percent(format, &flags)) == -1)
	{
		if (format[0] == '\n')
			return (flags.tot);
		return (-1);
	}
	if (!(str = ft_split_new(format, '%', i, &flags)) ||
		!(i = ft_analyze(format, str, i, &flags)))
	{
		free(str);
		return (-1);
	}
	va_end(flags.ap);
	free(str);
	return (flags.tot);
}
