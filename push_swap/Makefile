NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_REPO  = https://github.com/alex33fr/project42.git

CHECKER_URL = https://cdn.intra.42.fr/document/document/44055/checker_linux
CHECKER     = checker_linux

INCLUDES    = -Iincludes -I$(LIBFT_DIR)

SRC_DIR     = src
SRCS        = main.c \
			  ft_method_push.c \
			  ft_method_reverse_rotate.c \
			  ft_method_rotate.c \
			  ft_method_swap.c \
			  ft_push_swap.c \
			  ft_stack_tools.c \
			  ft_stack_tools2.c \
			  ft_algo_small_nbr.c \
			  ft_algo_turc1.c \
			  ft_algo_turc2.c \
			  ft_algo_turc3.c

OBJ_DIR     = obj
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TOTAL_FILES := $(words $(SRCS))
COUNT = 0

GREEN = \033[0;32m
BLUE  = \033[0;34m
RED   = \033[0;31m
RESET = \033[0m

all: $(CHECKER) $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@printf "\r$(GREEN)[Linking]$(RESET)                     "
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) || (printf "\n$(RED)Link error$(RESET)\n"; exit 1)
	@printf "\r$(GREEN)[100%%] $(NAME) ready [OK]$(RESET)\n"

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) tmp_libft >/dev/null 2>&1 || exit 1; \
		mv tmp_libft/libft $(LIBFT_DIR); \
		rm -rf tmp_libft; \
	fi
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 || exit 1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@PERCENT=$$(($(COUNT)*100/$(TOTAL_FILES))); \
	printf "\r$(GREEN)[%3d%%] %-30s$(RESET)" $$PERCENT "$<"; \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || exit 1

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(CHECKER):
	@if [ ! -f "$(CHECKER)" ]; then \
		printf "$(BLUE)Downloading checker_linux $(RESET)\n"; \
		curl -s $(CHECKER_URL) -o $(CHECKER) || exit 1; \
		chmod +x $(CHECKER); \
	fi

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1; fi
	@printf "$(GREEN)Clean [OK]$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@rm -rf $(LIBFT_DIR)
	@printf "$(GREEN)Fclean [OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
