NAME    = philo

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

INCLUDES  = -Iincludes

OBJ_DIR   = obj

GREEN = \033[0;32m
BLUE  = \033[0;34m
RED   = \033[0;31m
RESET = \033[0m

SRCS =	src/main.c \
		src/parsing.c \
		src/init.c \
		src/philo.c \
		src/forks.c \
		src/monitor.c \
		src/utils.c \
		src/trash.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[Compiling]$(RESET) $<\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || (printf "$(RED)Error in $<$(RESET)\n"; exit 1)

$(NAME): $(OBJS)
	@printf "$(GREEN)[Linking]$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME) || (printf "$(RED)Link error$(RESET)\n"; exit 1)
	@printf "$(GREEN)[100%%] ========[ $(NAME) is ready to work ]======== [OK]$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)Clean [OK]$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)Fclean [OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
