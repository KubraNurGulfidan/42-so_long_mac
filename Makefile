NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX = ./mlx/libmlx.a

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c error_utils.c fd_utils.c\
		file_check.c map_control_1.c map_control_2.c move_key.c so_long.c

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@make -C ./mlx &> /dev/null
	@$(CC) $(CFLAGS) $(SRC) $(MINILIBX) $(LDFLAGS) -o $(NAME)
	@echo "\033[0;33mThe game is ready to play!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./mlx clean
	@rm -rf $(OBJ) so_long.dSYM -s
	@echo "\033[0;33mObject files cleaned!"

fclean:	clean
	@make -C ./mlx clean -s
	@rm -rf $(NAME) -s

re:	fclean all

.PHONY:	all clean fclean re