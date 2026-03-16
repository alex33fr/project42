NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

INCLUDES    = -Iincludes

SRC_DIR     = src
SRCS        = main.c

OBJ_DIR     = obj
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TOTAL_FILES := $(words $(SRCS))
COUNT = 0

GREEN = \033[0;32m
BLUE  = \033[0;34m
RED   = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\r$(GREEN)[Linking]$(RESET)                     "
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) || (printf "\n$(RED)Link error$(RESET)\n"; exit 1)
	@printf "\r$(GREEN)[100%%] $(NAME) ready [OK]$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@PERCENT=$$(($(COUNT)*100/$(TOTAL_FILES))); \
	printf "\r$(GREEN)[%3d%%] %-30s$(RESET)" $$PERCENT "$<"; \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || exit 1

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)Clean [OK]$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)Fclean [OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
