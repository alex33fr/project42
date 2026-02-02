NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_ARCHIVE = minilibx-linux.tgz
MLX_URL     = https://cdn.intra.42.fr/document/document/45308/minilibx-linux.tgz
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_REPO  = https://github.com/alex33fr/project42.git

INCLUDES    = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC_DIR     = src
SRCS        = main.c \
              ft_open_read_prepare_map_fd.c \
              ft_checker_map.c \
              ft_free_map.c \
              ft_has_valid_chars.c \
              ft_init_game.c \
              ft_tracer_map.c \
              ft_find_solution.c \
              ft_close.c \
              ft_key_input.c \
              ft_try_move.c \
              ft_win.c \
              ft_init_player.c \
              ft_init_pickaxes.c \
              ft_game_start.c \
              ft_has_ber_extension.c \
              ft_gate.c \
			  ft_map_height.c \
			  ft_map_width.c \
			  ft_exit.c \
			  ft_error.c
SRC_PRE     = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR     = obj
OBJS        = $(SRC_PRE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m

all:
	@printf "\r$(GREEN)[  0%%] Initialisation$(RESET)"
	@$(MAKE) $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@printf "\r$(GREEN)[ 90%%] Edition des liens$(RESET)          "
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME) \
	|| (printf "\n$(RED)Erreur edition des liens$(RESET)\n"; exit 1)
	@printf "\r$(GREEN)[100%%] Build termine : $(NAME)$(RESET)\n"

$(MLX_LIB):
	@printf "\r$(GREEN)[ 10%%] MinilibX$(RESET)                   "
	@if [ ! -d "$(MLX_DIR)" ]; then \
		if [ ! -f "$(MLX_ARCHIVE)" ]; then \
			curl -L $(MLX_URL) -o $(MLX_ARCHIVE) || wget $(MLX_URL); \
		fi; \
		tar -xzf $(MLX_ARCHIVE); \
	fi
	@$(MAKE) -C $(MLX_DIR) >/dev/null 2>&1 \
	|| (printf "\n$(RED)Erreur compilation MinilibX$(RESET)\n"; exit 1)

$(LIBFT_LIB):
	@printf "\r$(GREEN)[ 40%%] Libft$(RESET)                       "
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) tmp_libft >/dev/null 2>&1 \
		|| (printf "\n$(RED)Erreur clone Libft$(RESET)\n"; exit 1); \
		mv tmp_libft/libft $(LIBFT_DIR); \
		rm -rf tmp_libft; \
	fi
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 \
	|| (printf "\n$(RED)Erreur compilation Libft$(RESET)\n"; exit 1)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "\r$(GREEN)[ 70%%] %s$(RESET)                      " "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ \
	|| (printf "\n$(RED)Erreur compilation %s$(RESET)\n" "$<"; exit 1)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "\r$(GREEN)[  0%%] Nettoyage$(RESET)                  "
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1; fi
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1; fi
	@printf "\r$(GREEN)[100%%] Nettoyage termine$(RESET)\n"

fclean: clean
	@printf "\r$(GREEN)[ 50%%] Suppression$(RESET)       "
	@rm -f $(NAME)
	@rm -rf $(LIBFT_DIR)
	@rm -rf $(MLX_DIR)
	@rm -f $(MLX_ARCHIVE)
	@printf "\r$(GREEN)[100%%] Fclean termine$(RESET)\n"

re:
	@printf "\r$(GREEN)[  0%%] Reconstruction$(RESET)             "
	@$(MAKE) clean
	@$(MAKE) all

.PHONY: all clean fclean re