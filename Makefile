NAME = so_long
BNAME = so_long_bonus

SRCS = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c parsing_commands.c \
		flood_fill.c parsing_commands2.c parsing_commands3.c \
		mandatory_commands.c mandatory_commands2.c \
		./libft/ft_split.c ./libft/ft_putchar.c \
		./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_substr.c \
		./libft/ft_strlcpy.c ./libft/ft_strnstr.c ./libft/ft_strjoin.c \
		./libft/ft_strlcat.c ./libft/ft_putstr_fd.c ./libft/ft_itoa.c ./libft/ft_strncmp.c \
		./libft/ft_putnbr_fd.c 

SRCSB = so_long_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		bonus_parsing_commands.c \
		flood_fill_bonus.c bonus_parsing_commands2.c \
		bonus_parsing_commands3.c \
		bonus_commands.c bonus_commands2.c \
		animation.c ./libft/ft_split.c ./libft/ft_putchar.c \
		./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_substr.c \
		./libft/ft_strlcpy.c ./libft/ft_strnstr.c ./libft/ft_strjoin.c \
		./libft/ft_strlcat.c ./libft/ft_putstr_fd.c ./libft/ft_itoa.c ./libft/ft_strncmp.c \
		./libft/ft_putnbr_fd.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include -g3
LDFLAGS = -L/usr/local/lib -lmlx -lXext -lX11
DEPS = so_long.h

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(LDFLAGS) -o $(NAME)

$(BNAME): $(SRCSB)
	$(CC) $(SRCSB) $(LDFLAGS) -o $(BNAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@


fclean:
	rm -f $(NAME) $(BNAME) 

re: fclean all
