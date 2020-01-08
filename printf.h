/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:01:42 by rzafari           #+#    #+#             */
/*   Updated: 2019/12/17 02:39:17 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	char	flag;
	int		width;
	char	widthchar;
	int		precision;
	char	precisionchar;
	int		point;
	char	type;
	int		size;
	int		size_neg;
	int		tot;
	int		mem;
	int		p;
	int		j;
	va_list	ap;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_search_percent(const char *format, t_flags *flags);
int				ft_search_percentnext(const char *format, t_flags *flags,
			int count, int i);
int				ft_analyze(const char *format, char **str, int i,
				t_flags *flags);
int				ft_isflag(char **str, t_flags *flags, int j, int l);
int				ft_iswidth(char **str, t_flags *flags, int j, int l);
int				ft_iswidthelseif(char **str, t_flags *flags, int j, int l);
int				ft_isprecision(char **str, t_flags *flags, int j, int l);
void			ft_isprecisionasterisk(t_flags *flags);
int				ft_isprecisionelseif(char **str, t_flags *flags, int j, int l);
int				ft_apply_flags(t_flags *flags);
int				ft_type_i(t_flags *flags);
int				ft_type_u(t_flags *flags);
int				ft_type_c(t_flags *flags);
int				ft_type_s(t_flags *flags);
void			ft_type_percent(t_flags *flags);
void			ft_type_percentelse(t_flags *flags, int len, char c);
int				ft_print0(int i, int size, int max, t_flags *flags);
int				ft_ps(int i, int size, int j, t_flags *flags);
int				ft_posflagi(char *s, int max, t_flags *flags);
int				ft_posflagizero(char *s, int max, t_flags *flags);
int				ft_posflagielse(char *s, int max, t_flags *flags);
int				ft_checkspecialcases(char *s, t_flags *flags);
int				ft_type_p(t_flags *flags);
void			ft_type_pnext(t_flags *flags, char *s, int i);
void			ft_type_pnegprecision(t_flags *flags);
int				ft_sizecalc(long n);
int				ft_type_x(t_flags *flags, int sorb);
int				ft_posflagx(char *s, int max, t_flags *flags);
int				ft_posflagxelse(char *s, int max, t_flags *flags);
int				ft_posflagu(char *s, int max, t_flags *flags);
int				returnfree(char *s, int i);
int				ft_printformat(const char *format, int i, t_flags *flags);
char			**ft_split_new(char const *s, char c, int len, t_flags *flags);
char			**freefunc(char **s);
char			*ft_strcrea(char const *s, char c);
char			*ft_convhexa(unsigned long i, int sorb);
char			*ft_strrev(char *str);
void			ft_istype(char **str, t_flags *flags, int j, int l);
void			ft_negflagi(char *s, int max, t_flags *flags);
void			ft_negflagx(char *s, int max, t_flags *flags);
void			ft_negflagu(char *s, int max, t_flags *flags);
void			ft_posflags(char *s, int len, t_flags *flags);
int				ft_posflagslenelse(char *s, int len, t_flags *flags);
int				ft_negflagsif(char *s, int len, t_flags *flags);
void			ft_posflagselse(char *s, int len, t_flags *flags);
void			ft_negflags(char *s, int len, t_flags *flags);
void			ft_initializeflags(t_flags *flags);
char			*ft_itoa(long n);
int				ft_isdigit(int i);
int				ft_atoi(const char *str);
int				ft_flags(char **str, t_flags *flags, int j);
int				ft_checkdoublepercent(const char *format, int i, t_flags *flags,
			int act);
int				ft_checkdoublepercente(const char *format, int i,
			t_flags *flags, int act);
int				ft_analyzewhil(const char *format, char **str, int i,
			t_flags *flags);
void			ft_analyzewhiln(const char *format, t_flags *flags);
void			ft_putstr_fd(char *s, int fd, t_flags *flags);
void			ft_putchar_fd(char c, int fd, t_flags *flags);
int				ft_strlen(const char *s);

#endif
