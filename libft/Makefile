SRCS =	ft_split.c \
		ft_strdup.c \
		ft_strlen.c \
		libft.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_putstr_fd.c \
		ft_itoa.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

NAME = libft.a
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
