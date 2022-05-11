NAME = so_long

SRC = main.c \
	get_map.c \
	get_next_line.c \
	get_next_line_utils.c \
	moves/moves.c \
	moves/enemy_moves.c \
	moves/display_moves.c \
	banner.c \
	finish.c \
	setup.c

OBJ = $(SRC:.c=.o)

RM = rm -f

HDRS = so_long.h

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME) ${OBJ}

re: $(NAME)

.PHONY: all clean fclean re