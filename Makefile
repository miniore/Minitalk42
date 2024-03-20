CLIENT = client
SERVER = server
LIBTF = Libft/libft.a
PRINTF = Libft/Printf/libftprintf.a

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)
	@echo "make    ✅"

$(CLIENT): $(CLIENT_OBJ) $(LIBTF) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(PRINTF) $(LIBTF) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(PRINTF) $(LIBTF) -o $(SERVER)

$(LIBTF):
	make -C Libft

$(PRINTF):
	make -C Libft/Printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./Libft
	make clean -C ./Libft/Printf
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "clean   🌪️"

fclean: clean
	make fclean -C ./Libft
	make fclean -C ./Libft/Printf
	rm -f $(CLIENT) $(SERVER)
	@echo "fclean  🔥"

re: fclean all

.SILENT:

.PHONY: all name clean fclean re