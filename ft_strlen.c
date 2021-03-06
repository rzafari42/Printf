/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:21:09 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/15 13:53:26 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
