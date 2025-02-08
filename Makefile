NAME = so_long

SRCS = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c command_help.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include -g3
LDFLAGS = -L/usr/local/lib -lmlx -lXext -lX11
DEPS = so_long.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(OBJS) -Llibft -lft $(LDFLAGS) -o $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all
