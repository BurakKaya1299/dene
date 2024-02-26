SRCS	= so_long.c ft_exit.c ft_free.c ft_check_map.c ft_init_game.c ft_init_map.c ft_render_map.c ft_handle_input.c ft_so_long_utils.c

NAME	= so_long

MLX		= libmlx.a

LIBFT	= libft.a

LIBF_DIR	= ./libft

MLX_DIR	= ./mlx

CC		=  gcc

CFLAGS	= -Wall -Wextra -Werror 

all: $(NAME)
	

$(NAME): $(MLX) $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -L $(LIBF_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(MLX): 
	make -s -C $(MLX_DIR) &> /dev/null

$(LIBFT):
	make -s -C $(LIBF_DIR)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBF_DIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all