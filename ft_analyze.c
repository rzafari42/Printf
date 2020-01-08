/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:19:20 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 21:55:25 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_flags(char **str, t_flags *flags, int j)
{
	int r;
	int l;

	l = 0;
	while (str[j][l] != '\0')
	{
		if (ft_isflag(str, flags, j, l) == -1)
		{
			if ((r = ft_iswidth(str, flags, j, l)) == -1)
			{
				if ((r = ft_isprecision(str, flags, j, l)) == -1)
					ft_istype(str, flags, j, l);
			}
			else
				l = r - 1;
		}
		l++;
	}
	return (returnfree(str[j], 1));
}

int		ft_printformat(const char *format, int i, t_flags *flags)
{
	while (format[i] && format[i] != '%')
	{
		ft_putchar_fd(format[i], 1, flags);
		i++;
	}
	return (i);
}

void	ft_analyzewhiln(const char *format, t_flags *flags)
{
	while (format[flags->mem] && format[flags->mem] != 'c' &&
	format[flags->mem] != 's' && format[flags->mem] != 'd' &&
	format[flags->mem] != 'p' && format[flags->mem] != 'i' &&
	format[flags->mem] != 'u' && format[flags->mem] != 'x' &&
	format[flags->mem] != 'X' && format[flags->mem] != ' ')
		flags->mem++;
	if (format[flags->mem] == ' ')
		ft_putchar_fd(' ', 1, flags);
	flags->mem++;
}

int		ft_analyzewhil(const char *format, char **str, int i, t_flags *flags)
{
	while (flags->j < i)
	{
		ft_initializeflags(flags);
		flags->mem = ft_printformat(format, flags->mem, flags);
		if (format[flags->mem] == '%' &&
			!(flags->p = ft_checkdoublepercent(format, flags->mem, flags, 1)))
		{
			ft_flags(str, flags, flags->j);
			flags->j++;
		}
		if (flags->p != 0)
			flags->mem = flags->p + 1;
		flags->p = ft_checkdoublepercent(format, flags->mem, flags, 1);
		ft_analyzewhiln(format, flags);
		if (!(ft_apply_flags(flags)))
			return (returnfree(str[flags->j], 0));
	}
	return (1);
}

int		ft_analyze(const char *format, char **str, int i, t_flags *flags)
{
	int l;

	flags->mem = 0;
	flags->p = 0;
	flags->j = 0;
	flags->mem = ft_printformat(format, flags->mem, flags);
	l = ft_checkdoublepercent(format, flags->mem, flags, 1);
	flags->mem = l != 0 ? l + 1 : flags->mem;
	if (!(ft_analyzewhil(format, str, i, flags)))
		return (0);
	while (format[flags->mem] != '\0')
	{
		if ((flags->p = ft_checkdoublepercent(format, flags->mem, flags, 1))
			!= 0)
			flags->mem = flags->p + 1;
		else
			flags->mem = ft_printformat(format, flags->mem, flags);
	}
	return (returnfree(str[flags->j], 1));
}
