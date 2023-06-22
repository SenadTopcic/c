NAME = push_swap

P_FILES = ft_split.c \
			push_swap.c \
			error_handler.c \
			push_swap_func_1.c \
			push_swap_func_2.c \
			rules_p_swap.c \
			rules_p_swap_1.c \
			rules_p_swap_2.c \
			rules_p_swap_3.c \
			sort_5_4_3.c \
			sort_radix.c \
			rules_index.c \

P_O_FILES = ${P_FILES:.c=.o}


CFLAGS = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME): $(P_O_FILES)
	@cc $(CFLAGS) $(P_FILES) -o $(NAME)


clean:
	rm -f $(P_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all


