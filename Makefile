NAME = so_long

SRC = main.c \
	get_map.c \
	get_next_line.c \
	get_next_line_utils.c \
	moves/moves.c \
	moves/player_moves.c \
	moves/display_moves.c \
	banner.c \
	finish.c

OBJ = $(SRC:.c=.o)

RM = rm -f

HDRS = so_long.h

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./mlx
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

ex: $(NAME)
	./$(NAME) maps/map2.ber
	make clean
	make -C ./mlx/ clean

clean:
	${RM} $(OBJ)
# make -C ./mlx/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./mlx/ clean

re: $(NAME)

.PHONY: all clean fclean re