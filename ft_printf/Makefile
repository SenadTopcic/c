# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopcic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 12:51:40 by stopcic           #+#    #+#              #
#    Updated: 2022/11/08 11:04:44 by stopcic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = ft_printf.c ft_int_hex.c ft_int_ptr.c ft_itoa_pf.c ft_putchar_pf.c\
		ft_putstr_pf.c
O_FILES = ${C_FILES:.c=.o}

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

all:
	@gcc $(CFLAGS) -c $(C_FILES)
	@ar rcs $(NAME) $(O_FILES)
$(NAME): all

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
