/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:39:27 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 18:27:22 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_percentelse(t_flags *flags, int len, char c)
{
	ft_ps(len, 0, 0, flags);
	ft_putchar_fd(c, 1, flags);
}

void		ft_type_percent(t_flags *flags)
{
	int		len;
	char	c;

	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	len = flags->width;
	if (len)
		len--;
	c = (flags->type == '\0') ? '%' : va_arg(flags->ap, int);
	if (flags->flag == '-' || flags->flag == '0')
	{
		if (flags->flag == '-')
		{
			ft_putchar_fd(c, 1, flags);
			ft_ps(len, 0, 0, flags);
		}
		if (flags->flag == '0')
		{
			ft_print0(len, 0, 0, flags);
			ft_putchar_fd(c, 1, flags);
		}
	}
	else
		ft_type_percentelse(flags, len, c);
}
