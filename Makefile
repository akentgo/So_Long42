NAME		= so_long
SRC			= $(GAME_DATA)
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))
GAME		= create_map.c read_map.c parser.c get_next_line.c get_next_line_utils.c so_long.c put_images.c player_movement.c path.c
GAME_DATA	= $(addprefix srcs/, $(GAME))
OBJ_DIR		= objs/
OBJ			= $(patsubst srcs/%.c, objs/%.o, $(SRC))
STANDARD_FLAGS	= -Wall -Werror -Wextra -g -O0
INCLUDE		= -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@echo "Compiling..."
	@gcc $(STANDARD_FLAGS) $^ $(LIBFT) $(INCLUDE) -o $(NAME)

$(OBJ_DIR)%.o: srcs/%.c
	@mkdir -p $(@D)
	@gcc $(STANDARD_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re