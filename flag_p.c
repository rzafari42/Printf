/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:19:23 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/17 00:04:08 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_pnegprecision(t_flags *flags)
{
	if (flags->flag == '-')
		ft_putstr_fd("0x", 1, flags);
	if (flags->width > 0)
		ft_ps(flags->width - 2, 0, 0, flags);
	if (flags->flag != '-')
		ft_putstr_fd("0x", 1, flags);
}

void	ft_type_pnext(t_flags *flags, char *s, int i)
{
	if (flags->flag == '-')
	{
		ft_putstr_fd("0x", 1, flags);
		ft_putstr_fd(s, 1, flags);
	}
	if (flags->width > 0)
		ft_ps(flags->width, i, 0, flags);
	if (flags->flag != '-')
	{
		ft_putstr_fd("0x", 1, flags);
		ft_putstr_fd(s, 1, flags);
	}
}

int		ft_type_p(t_flags *flags)
{
	int				i;
	char			*s;
	unsigned long	d;

	i = 0;
	s = NULL;
	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	d = va_arg(flags->ap, long long);
	if (d == 0 && flags->precision == -1)
		ft_type_pnegprecision(flags);
	else
	{
		if (!(s = ft_convhexa(d, 0)))
			return (0);
		while (s[i])
			i++;
		i += 2;
		ft_type_pnext(flags, s, i);
	}
	return (returnfree(s, 1));
}
