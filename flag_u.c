/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:24:05 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 22:31:23 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_negflagu(char *s, int max, t_flags *flags)
{
	if (flags->precision > flags->size)
		max = ft_print0(flags->precision, flags->size, max, flags);
	ft_putstr_fd(s, 1, flags);
	max = max - flags->size;
	max = ft_ps(max, 0, 0, flags);
}

int		ft_posflagu(char *s, int max, t_flags *flags)
{
	if (flags->precision == 0 && flags->width)
	{
		ft_print0(flags->width, flags->size, max, flags);
		ft_putstr_fd(s, 1, flags);
		return (1);
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

int		ft_type_u(t_flags *flags)
{
	char	*s;
	int		max;

	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	if (flags->precisionchar == '*')
		flags->precision = va_arg(flags->ap, int);
	if (!(s = ft_itoa(va_arg(flags->ap, unsigned int))))
		return (0);
	flags->size = ft_strlen(s);
	if (flags->width == 0 && flags->precision == 0)
		max = flags->size;
	else
		max = (flags->width > flags->precision) ?
	flags->width : flags->precision;
	if (!(ft_checkspecialcases(s, flags)))
		return (returnfree(s, 1));
	if (flags->flag == '-')
		ft_negflagu(s, max, flags);
	else
		ft_posflagu(s, max, flags);
	free(s);
	return (1);
}
