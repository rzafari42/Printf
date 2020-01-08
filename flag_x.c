/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:17:26 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 22:28:21 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_negflagx(char *s, int max, t_flags *flags)
{
	if (s[0] == '-')
	{
		ft_putchar_fd('-', 1, flags);
		max--;
		if (flags->precision > flags->size)
			max = ft_print0(flags->precision, flags->size, max, flags);
		ft_putstr_fd(s + 1, 1, flags);
		max = max - flags->size;
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

int		ft_posflagxelse(char *s, int max, t_flags *flags)
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

int		ft_posflagx(char *s, int max, t_flags *flags)
{
	if (s[0] == '-')
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
			if (flags->precision > 1)
				ft_ps(flags->width, flags->precision, 1, flags);
			else
				ft_ps(flags->width, flags->precision, flags->size,
					flags);
		}
		ft_putchar_fd('-', 1, flags);
		if (flags->precision > flags->size)
			ft_print0(flags->precision, flags->size, max, flags);
		ft_putstr_fd(s + 1, 1, flags);
	}
	else if (ft_posflagxelse(s, max, flags))
		return (1);
	return (1);
}

int		ft_type_x(t_flags *flags, int sorb)
{
	char	*s;
	int		max;

	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	if (flags->precisionchar == '*')
		flags->precision = va_arg(flags->ap, int);
	if (!(s = ft_convhexa(va_arg(flags->ap, unsigned int), sorb)))
		return (returnfree(s, 0));
	flags->size = ft_strlen(s);
	max = (flags->width > flags->precision) ? flags->width : flags->precision;
	if (flags->width == 0 && flags->precision == 0)
		max = flags->size;
	if (!(ft_checkspecialcases(s, flags)))
		return (returnfree(s, 1));
	if (flags->flag == '-')
		ft_negflagx(s, max, flags);
	else if (!(ft_posflagx(s, max, flags)))
		return (returnfree(s, 1));
	return (returnfree(s, 1));
}
