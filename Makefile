# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:43:22 by rzafari           #+#    #+#              #
#    Updated: 2019/12/15 21:02:30 by rzafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a
HEADER = printf.h
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRCS = printf.c\
		ft_analyze.c\
		ft_split_new.c\
		ft_utils00.c\
		ft_utils01.c\
		flag_c.c\
		flag_i.c\
		flag_p.c\
		flag_s.c\
		flag_u.c\
		flag_x.c\
		flag_percent.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_isdigit.c\
		ft_iswidth.c\
		ft_isprecision.c\
		ft_istype.c\
		ft_isflag.c\
		ft_searchpercent.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -I$(HEADER) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re
