/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:44:17 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 22:28:56 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_negflagi(char *s, int max, t_flags *flags)
{
	if (s[0] == '-')
	{
		ft_putchar_fd('-', 1, flags);
		max--;
		if (flags->precision > flags->size_neg)
			max = ft_print0(flags->precision, flags->size_neg, max, flags);
		ft_putstr_fd(s + 1, 1, flags);
		max = max - flags->size_neg;
		max = ft_ps(max, 0, 0, flags);
	}
	else
	{
		if (flags->precision > flags->size)
			max = ft_print0(flags->precision, flags->size, max, flags);
		ft_putstr_fd(s, 1, flags);
		max = max - flags->size;
		max = ft_ps(max, 0, 0, flags);
	}
}

int		ft_posflagielse(char *s, int max, t_flags *flags)
{
	if (flags->precision == 0 && flags->width)
	{
		ft_print0(flags->width, flags->size, max, flags);
		ft_putstr_fd(s, 1, flags);
		return (0);
	}
	if (flags->width > flags->precision && flags->precision >= flags->size)
		ft_ps(flags->width, flags->precision, 0, flags);
	if (flags->width > flags->precision && flags->precision < flags->size)
		ft_ps(flags->width, flags->size, 0, flags);
	if (flags->precision > flags->size)
		ft_print0(flags->precision, flags->size, max, flags);
	ft_putstr_fd(s, 1, flags);
	return (1);
}

int		ft_posflagizero(char *s, int max, t_flags *flags)
{
	if (flags->precision == 0 && flags->width)
	{
		ft_putchar_fd('-', 1, flags);
		ft_print0(flags->width, flags->size, max, flags);
		ft_putstr_fd(s + 1, 1, flags);
		return (0);
	}
	if (flags->width > flags->precision)
	{
		if (flags->precision > 1 && flags->precision > flags->size)
			ft_ps(flags->width, flags->precision, 1, flags);
		else if (flags->precision > 1 && flags->precision < flags->size)
			ft_ps(flags->width, flags->size, 0, flags);
		else if (flags->precision > 1)
			ft_ps(flags->width, flags->size, 1, flags);
		else if (flags->precision == 1)
			ft_ps(flags->width, flags->size, 0, flags);
	}
	ft_putchar_fd('-', 1, flags);
	if (flags->precision > flags->size_neg)
		ft_print0(flags->precision, flags->size_neg, max, flags);
	ft_putstr_fd(s + 1, 1, flags);
	return (1);
}

int		ft_posflagi(char *s, int max, t_flags *flags)
{
	if (s[0] == '-')
	{
		if (!(ft_posflagizero(s, max, flags)))
			return (0);
	}
	else
		ft_posflagielse(s, max, flags);
	return (1);
}

int		ft_type_i(t_flags *flags)
{
	char	*s;
	int		max;

	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	if (flags->precisionchar == '*')
		flags->precision = va_arg(flags->ap, int);
	if (!(s = ft_itoa(va_arg(flags->ap, int))))
		return (0);
	flags->size = ft_strlen(s);
	flags->size_neg = ft_strlen(s + 1);
	max = (flags->width > flags->precision) ? flags->width : flags->precision;
	if (flags->width == 0 && flags->precision == 0)
		max = (s[0] == '-') ? flags->size_neg : flags->size;
	if (!(ft_checkspecialcases(s, flags)))
		return (returnfree(s, 1));
	if (flags->flag == '-')
		ft_negflagi(s, max, flags);
	else if (!(ft_posflagi(s, max, flags)))
		return (returnfree(s, 1));
	return (returnfree(s, 1));
}
