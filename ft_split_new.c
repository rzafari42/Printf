/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:14:08 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/15 15:48:17 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strcrea(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	c = '%';
	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != 'c' && s[i] != 's' && s[i] != 'd'
		&& s[i] != 'p' && s[i] != 'i' && s[i] != 'u' && s[i] != 'x'
		&& s[i] != 'X' && s[i] != ' ')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[j++] = '%';
	i = 0;
	i++;
	while (s[i] != '\0' && s[i] != 'c' && s[i] != 's' && s[i] != 'd'
		&& s[i] != 'p' && s[i] != 'i' && s[i] != 'u' && s[i] != 'x'
		&& s[i] != 'X' && s[i] != ' ')
		str[j++] = s[i++];
	str[j] = s[i];
	str[++j] = '\0';
	return (str);
}

char			**freefunc(char **s)
{
	while (s)
	{
		free(s);
		s = NULL;
		s++;
	}
	return (NULL);
}

char			**ft_split_new(char const *s, char c, int len, t_flags *flags)
{
	int				i;
	int				j;
	int				l;
	char			**res;

	i = 0;
	j = 0;
	if (!s || !(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		l = ft_checkdoublepercent(s, i, flags, 0);
		i = l != 0 ? l : i;
		if (s[i] != '\0' && s[i] == c && l == 0)
			if (!(res[j++] = ft_strcrea(&(s[i]), c)))
				return (freefunc(res));
		i++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	res[len] = NULL;
	return (res);
}
