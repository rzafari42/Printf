/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/17 02:40:14 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_convhexa(unsigned long i, int sorb)
{
	char	*s;
	int		remainder;
	int		size;

	size = ft_sizecalc(i);
	if (!(s = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	if (i == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	size = 0;
	while (i != 0)
	{
		remainder = i % 16;
		i = i / 16;
		if (remainder >= 10 && remainder <= 15)
			s[size++] = (sorb == 1) ? remainder + 87 - 32 : remainder + 87;
		else
			s[size++] = remainder % 10 + 48;
	}
	s[size] = '\0';
	return (s = ft_strrev(s));
}

int		returnfree(char *s, int i)
{
	free(s);
	return (i);
}

void	ft_initializeflags(t_flags *flags)
{
	flags->flag = '\0';
	flags->width = 0;
	flags->widthchar = '\0';
	flags->precision = 0;
	flags->precisionchar = '\0';
	flags->point = 0;
	flags->type = '\0';
	flags->size = 0;
	flags->size_neg = 0;
}

int		ft_posflagslenelse(char *s, int len, t_flags *flags)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = (len > i) ? ft_ps(len, i, 0, flags) : len;
	len = (flags->precision < 0) ? ft_ps(len, 0, 0, flags) : len;
	if (flags->precision == 0 && flags->point == 2)
	{
		ft_ps(len, 0, 0, flags);
		return (0);
	}
	if (flags->precision == 0 && flags->point != 1)
		ft_putstr_fd(s, 1, flags);
	return (1);
}
