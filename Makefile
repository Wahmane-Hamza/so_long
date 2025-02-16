NAME = so_long
BNAME = so_long_bonus

SRCS = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c parsing_commands.c \
		flood_fill.c parsing_commands2.c parsing_commands3.c \
		mandatory_commands.c mandatory_commands2.c \

SRCSB = so_long_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		bonus_parsing_commands.c \
		flood_fill_bonus.c bonus_parsing_commands2.c \
		bonus_parsing_commands3.c \
		bonus_commands.c bonus_commands2.c bonus_commands3.c bonus_commands4.c \
		animation.c animation2.c  animation3.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include -g3
LDFLAGS = -L/usr/local/lib -lmlx -lXext -lX11
DEPS = so_long.h

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(OBJS) -Llibft -lft  $(LDFLAGS) -o $(NAME)

$(BNAME): $(OBJSB)
	@make -C libft
	$(CC) $(OBJSB) -Llibft -lft  $(LDFLAGS) -o $(BNAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME) $(BNAME) 

re: fclean all
