/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:41:39 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 18:26:32 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_iswidth(char **str, t_flags *flags, int j, int l)
{
	int	res;

	if (l > 0 && flags->precision == 0)
	{
		if (str[j][l] == '*' && str[j][l - 1] != '.')
		{
			flags->widthchar = '*';
			return (++l);
		}
		else if (ft_isdigit(str[j][l]) && str[j][l - 1] != '.' &&
			str[j][l] != '0' && (str[j][l - 1] == '0'
			|| str[j][l - 1] == '-' || str[j][l - 1] == '%'))
		{
			if (!(res = ft_iswidthelseif(str, flags, j, l)))
				return (0);
			return (res);
		}
	}
	return (-1);
}

int		ft_iswidthelseif(char **str, t_flags *flags, int j, int l)
{
	int		mem;
	int		k;
	char	*new_str_width;

	mem = l;
	k = 0;
	while (str[j][l] && (str[j][l] != '.' && str[j][l] != 'c' &&
		str[j][l] != 's' && str[j][l] != 'd' && str[j][l] != 'p'
		&& str[j][l] != 'i' && str[j][l] != 'u' && str[j][l] != 'x'
		&& str[j][l] != 'X'))
	{
		l++;
		k++;
	}
	if (!(new_str_width = (char *)malloc(sizeof(char) * (k + 1))))
		return (0);
	k = 0;
	while (str[j][mem] && (str[j][mem] != '.' && str[j][mem] != 'c'
		&& str[j][mem] != 's' && str[j][mem] != 'd'
		&& str[j][mem] != 'p' && str[j][mem] != 'i' && str[j][mem] != 'u'
		&& str[j][mem] != 'x' && str[j][mem] != 'X'))
		new_str_width[k++] = str[j][mem++];
	new_str_width[k] = '\0';
	flags->width = ft_atoi(new_str_width);
	return (returnfree(new_str_width, l));
}
