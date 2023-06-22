# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopcic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 09:51:50 by stopcic           #+#    #+#              #
#    Updated: 2022/10/28 20:18:23 by stopcic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c\
		ft_toupper.c
O_FILES = ${C_FILES:.c=.o}
B_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c
BO_FILES =${B_FILES:.c=.o}
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

all:
	@gcc $(CFLAGS) -c $(C_FILES)
	@ar rcs $(NAME) $(O_FILES)
$(NAME): all
clean:
	rm -f $(O_FILES) $(BO_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus:
	@gcc $(CFLAGS) -c $(B_FILES) $(C_FILES)
	@ar rcs $(NAME) $(BO_FILES) $(O_FILES)
