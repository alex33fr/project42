NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

INCLUDES    = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC_DIR     = src
SRCS        = main.c \
			ft_open_read_prepare_map_fd.c \
			ft_checker_map.c \
			ft_free_map.c \
			ft_has_valid_chars.c 
SRC_PRE		= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR     = obj
OBJS        = $(SRC_PRE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
