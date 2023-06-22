NAME = client server

SERVER_FILES = minitalk_utilis.c server.c
CLIENT_FILES = minitalk_utilis.c client.c

C_O_FILES = ${CLIENT_FILES:.c=.o}
S_O_FILES = ${SERVER_FILES:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME): $(C_O_FILES) $(S_O_FILES)
	@cc $(CFLAGS) $(CLIENT_FILES) -o client
	@cc $(CFLAGS) $(SERVER_FILES) -o server


clean:
	rm -f $(C_O_FILES)
	rm -f $(S_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
