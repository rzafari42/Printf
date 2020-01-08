/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprecision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:42:52 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/17 02:10:32 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_isprecisionasterisk(t_flags *flags)
{
	flags->precisionchar = '*';
	flags->point = 2;
}

int		ft_isprecision(char **str, t_flags *flags, int j, int l)
{
	int		res;

	if (l > 0)
	{
		if (str[j][l] == '*')
		{
			ft_isprecisionasterisk(flags);
			return (++l);
		}
		if (((str[j][l] == '0' && (!ft_isdigit(str[j][l + 1]))) ||
			(!ft_isdigit(str[j][l]))) && str[j][l - 1] == '.')
		{
			if (!ft_isdigit(str[j][l]) && str[j][l - 1] == '.')
				flags->point = 1;
			return ((flags->precision = -1));
		}
		else if (ft_isdigit(str[j][l]) && str[j][l - 1] == '.')
		{
			if (!(res = ft_isprecisionelseif(str, flags, j, l)))
				return (0);
			flags->point = (flags->precision == 0) ? 1 : flags->point;
			return (res);
		}
	}
	return (-1);
}

int		ft_isprecisionelseif(char **str, t_flags *flags, int j, int l)
{
	int		mem;
	int		k;
	char	*new_str_precision;

	k = 0;
	mem = l;
	while (str[j][l] && (str[j][l] != 'c' && str[j][l] != 's'
		&& str[j][l] != 'd' && str[j][l] != 'p' && str[j][l] != 'i'
		&& str[j][l] != 'u' && str[j][l] != 'x' && str[j][l] != 'X'))
	{
		l++;
		k++;
	}
	if (!(new_str_precision = (char *)malloc(sizeof(char) * (k + 1))))
		return (0);
	k = 0;
	while (str[j][mem] && (str[j][mem] != 'c' && str[j][mem] != 's'
		&& str[j][mem] != 'd' && str[j][mem] != 'p'
		&& str[j][mem] != 'i' && str[j][mem] != 'u'
		&& str[j][mem] != 'x' && str[j][mem] != 'X'))
		new_str_precision[k++] = str[j][mem++];
	new_str_precision[k] = '\0';
	flags->precision = ft_atoi(new_str_precision);
	return (returnfree(new_str_precision, l));
}
