/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:51:49 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/15 20:06:56 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print0(int i, int size, int max, t_flags *flags)
{
	while (i - size > 0)
	{
		ft_putchar_fd('0', 1, flags);
		i--;
		max--;
	}
	return (max);
}

int		ft_ps(int i, int size, int j, t_flags *flags)
{
	while (i - size - j > 0)
	{
		ft_putchar_fd(' ', 1, flags);
		i--;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	mem;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = -1;
	while (++j < --i)
	{
		mem = str[i];
		str[i] = str[j];
		str[j] = mem;
	}
	return (str);
}

int		ft_sizecalc(long n)
{
	int	res;

	res = (n <= 0 ? 1 : 0);
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

int		ft_checkspecialcases(char *s, t_flags *flags)
{
	if (flags->precision == -1 && s[0] == '0' && s[1] == '\0')
	{
		if (flags->width > 0)
			ft_ps(flags->width, 0, 0, flags);
		return (0);
	}
	if (flags->precision == -1 && flags->flag == '0')
	{
		if (flags->width > 0)
			ft_ps(flags->width, flags->size, 0, flags);
		ft_putstr_fd(s, 1, flags);
		return (0);
	}
	if (flags->flag == '\0' && (flags->precision == 0
		|| flags->precision == -1))
	{
		ft_ps(flags->width, flags->size, 0, flags);
		ft_putstr_fd(s, 1, flags);
		return (0);
	}
	return (1);
}
