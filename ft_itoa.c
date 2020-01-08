/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:35:47 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/14 20:05:53 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					*ft_itoa(long n)
{
	unsigned int		num;
	char				*itoa;
	int					size;

	num = (n < 0 ? -n : n);
	size = ft_sizecalc(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size--] = '\0';
	while (size >= 0)
	{
		itoa[size] = num % 10 + 48;
		num = num / 10;
		size--;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
