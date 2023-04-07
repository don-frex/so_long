NAME = so_long

SRC = so_long.c libft_funcs.c check_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRC:.c:.o)

CC = CC

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all