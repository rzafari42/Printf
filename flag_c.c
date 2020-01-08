/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:53:44 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 22:28:34 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_type_c(t_flags *flags)
{
	int						len;
	unsigned char			c;

	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	len = flags->width;
	if (len)
		len--;
	c = (flags->type == '\0') ? '%' : (unsigned char)va_arg(flags->ap, int);
	if (flags->flag == '-')
	{
		ft_putchar_fd(c, 1, flags);
		ft_ps(len, 0, 0, flags);
	}
	else
	{
		ft_ps(len, 0, 0, flags);
		ft_putchar_fd(c, 1, flags);
	}
	return (1);
}
