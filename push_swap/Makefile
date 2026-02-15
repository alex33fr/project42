NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_REPO  = https://github.com/alex33fr/project42.git

INCLUDES    = -Iincludes -I$(LIBFT_DIR)

SRC_DIR     = src
SRCS        = main.c
SRC_PRE     = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR     = obj
OBJS        = $(SRC_PRE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m

all:
	@printf "\r$(GREEN)[  0%%] Initialisation$(RESET)"
	@$(MAKE) $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@printf "\r$(GREEN)[ 90%%] Edition des liens$(RESET)          "
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) \
	|| (printf "\n$(RED)Erreur edition des liens$(RESET)\n"; exit 1)
	@printf "\r$(GREEN)[100%%] Build termine : $(NAME)$(RESET)\n"

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
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1; fi
	@printf "\r$(GREEN)[100%%] Nettoyage termine$(RESET)\n"

fclean: clean
	@printf "\r$(GREEN)[ 50%%] Suppression$(RESET)       "
	@rm -f $(NAME)
	@rm -rf $(LIBFT_DIR)
	@printf "\r$(GREEN)[100%%] Fclean termine$(RESET)\n"

re:
	@printf "\r$(GREEN)[  0%%] Reconstruction$(RESET)             "
	@$(MAKE) clean
	@$(MAKE) all

.PHONY: all clean fclean re