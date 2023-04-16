NAME = so_long

CC = CC

CFLAGS = -Wall -Werror -Wextra

SRC = so_long.c libft_funcs.c check_map.c ft_split.c check_characters.c gnl/get_next_line.c gnl/get_next_line_utils.c search_map.c check_mov.c check_if_valid.c display/display.c

OBJS = $(patsubst %.c, %.o, $(SRC))

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY:all bonus clean fclean re