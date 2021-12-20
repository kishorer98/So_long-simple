PATH_GAME = ./game/
PATH_GNL = ./gnl/
PATH_UTILS = ./utils/
PATH_MAP = ./map/
PATH_MLX = ./mlx_linux/
PATH_OBJ = ./objs/
SRC = ./%.c

FILES = errors.c $(PATH_GAME)flow_game.c $(render.c) \
		$(PATH_GAME)init_game.c $(PATH_GAME)render.c $(PATH_GAME)reset.c $(PATH_GNL)get_next_line_utils.c $(PATH_GNL)get_next_line.c \
		$(PATH_MAP)config_map.c $(PATH_MAP)set_map.c $(PATH_UTILS)ft_bzero.c $(PATH_UTILS)ft_calloc.c \
		$(PATH_UTILS)ft_itoa.c $(PATH_UTILS)ft_strnstr.c

OBJS = $(patsubst $(SRC), $(PATH_OBJ)/%.o, $(FILES))

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Ilmlx -lXext -lX11 -lbsd -I $(PATH_MLX) -L $(PATH_MLX)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(OBJS) so_long.c $(MLXFLAGS) $(PATH_MLX)libmlx.a -o $(NAME)

$(PATH_OBJ)/%.o:	$(SRC)
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)game
	@mkdir -p $(PATH_OBJ)gnl
	@mkdir -p $(PATH_OBJ)map
	@mkdir -p $(PATH_OBJ)utils
	$(CC) $(CFLAGS)  -I. -c $< -o $@

norm: 
	norminette map game gnl utils errors.c so_long.c utils.h

clean:  
	rm -rf $(PATH_OBJ)

fclean: clean
	make clean -C $(PATH_MLX)
	rm -rf $(NAME)

re: fclean all

teste:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long