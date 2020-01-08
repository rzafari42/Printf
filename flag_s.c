/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:41:37 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/17 02:40:15 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_negflagsif(char *s, int len, t_flags *flags)
{
	int i;

	i = 0;
	while (s[i] && flags->precision > 0)
	{
		ft_putchar_fd(s[i], 1, flags);
		i++;
		flags->precision--;
		if (len != 0)
			len--;
	}
	return (len);
}

void	ft_negflags(char *s, int len, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->precision > 0)
		len = ft_negflagsif(s, len, flags);
	else
	{
		if (flags->precision <= 0 && flags->point == 1)
		{
			len = ft_ps(len, 0, 0, flags);
			return ;
		}
		if (flags->precision == 0 && flags->point == 2)
		{
			if (len != 0)
				ft_ps(len, 0, 0, flags);
			return ;
		}
		ft_putstr_fd(s, 1, flags);
		len = len - ft_strlen(s);
	}
	ft_ps(len, 0, 0, flags);
}

void	ft_posflagselse(char *s, int len, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->precision > 0)
	{
		while (s[i] && flags->precision-- > 0)
		{
			ft_putchar_fd(s[i++], 1, flags);
			len = (len != 0) ? len-- : len;
		}
	}
	else
	{
		if (flags->precision == -1 && len == 0)
			return ;
		if (flags->precision == 0 && flags->point == 2)
			return ;
		ft_putstr_fd(s, 1, flags);
	}
}

void	ft_posflags(char *s, int len, t_flags *flags)
{
	int i;

	i = 0;
	if (len > 0)
	{
		if (flags->precision > 0)
		{
			len = (flags->precision < ft_strlen(s)) ?
			ft_ps(len, flags->precision, 0, flags) :
			ft_ps(len, ft_strlen(s), 0, flags);
			while (s[i] && flags->precision-- > 0)
				ft_putchar_fd(s[i++], 1, flags);
		}
		else
		{
			if (!ft_posflagslenelse(s, len, flags))
				return ;
		}
	}
	else
		ft_posflagselse(s, len, flags);
}

int		ft_type_s(t_flags *flags)
{
	int		len;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (flags->widthchar == '*')
		flags->width = va_arg(flags->ap, int);
	flags->flag = flags->width < 0 ? '-' : flags->flag;
	flags->flag = flags->flag == '0' ? '\0' : flags->flag;
	flags->width = flags->width < 0 ? (flags->width * -1) : flags->width;
	len = flags->width;
	if (flags->precisionchar == '*')
		flags->precision = va_arg(flags->ap, int);
	s = va_arg(flags->ap, char *);
	if (s == NULL)
		s = "(null)";
	if (flags->flag == '-')
		ft_negflags(s, len, flags);
	else
		ft_posflags(s, len, flags);
	return (1);
}
