/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:44:06 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/16 18:26:04 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_istype(char **str, t_flags *flags, int j, int l)
{
	if (str[j][l] == 'c' || str[j][l] == 's' || str[j][l] == 'd'
		|| str[j][l] == 'p' || str[j][l] == 'i' || str[j][l] == 'u'
		|| str[j][l] == 'x' || str[j][l] == 'X')
		flags->type = str[j][l];
}
