/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchpercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:25:59 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/15 20:59:18 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_checkdoublepercente(const char *format, int i, t_flags *flags, int act)
{
	char	**str;
	int		j;

	j = 0;
	if (format[i - 1] == '%' && format[i + 1] == '%')
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * 2)))
		return (0);
	if (!(str[0] = (char*)malloc(sizeof(char) * (i - flags->mem + 2))))
		return (0);
	str[0][j++] = '%';
	while (format[++flags->mem] != '\0' && format[flags->mem] != '%')
		str[0][j++] = format[flags->mem];
	str[0][j] = '\0';
	str[1] = NULL;
	if (act == 1)
	{
		ft_flags(str, flags, 0);
		ft_type_percent(flags);
		free(str);
		return (i);
	}
	free(*str);
	free(str);
	return (i);
}

int	ft_checkdoublepercent(const char *format, int i, t_flags *flags, int act)
{
	flags->mem = i;
	i++;
	while (format[i] != '\0' && format[i] != '%' && (format[i] == '*' ||
		format[i] == '-' || format[i] == '.' || ft_isdigit(format[i])))
		i++;
	if (format[i] != '\0' && format[i] == '%')
	{
		if (format[i - 1] == '%')
		{
			ft_initializeflags(flags);
			if (act == 1)
				if (!(ft_type_c(flags)))
					return (0);
			return (i);
		}
		else
		{
			ft_initializeflags(flags);
			return (ft_checkdoublepercente(format, i, flags, act));
		}
	}
	return (0);
}

int	ft_search_percentnext(const char *format, t_flags *flags, int count, int i)
{
	int l;

	l = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
			i++;
		if (format[i] != '\0' && format[i] == '%')
		{
			l = ft_checkdoublepercent(format, i, flags, 0);
			if (l == 0)
			{
				i++;
				count++;
			}
			else
				i = l + 1;
			while (format[i] && format[i] != 'c' && format[i] != 's' &&
			format[i] != 'd' && format[i] != 'p' && format[i] != 'i' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X' &&
			format[i] != '%')
				i++;
		}
	}
	return (count);
}

int	ft_search_percent(const char *format, t_flags *flags)
{
	ft_initializeflags(flags);
	if (format[0] == '\n' && (!format[1] || format[1] == '\n'))
	{
		ft_putstr_fd((char *)format, 1, flags);
		return (-1);
	}
	return (ft_search_percentnext(format, flags, 0, 0));
}
