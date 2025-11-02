CC      = cc

CFLAGS  = -Wall -Wextra -Werror -I. -Ilibft

AR	= ar rcs

NAME	= libftprintf.a

SRCS    = ft_printf.c \
		tools/ft_print_char.c \
		tools/ft_print_string.c \
		tools/ft_print_int.c \
		tools/ft_print_ptr.c \

OBJS    = $(SRCS:%.c=%.o)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY:	all	clean	fclean	re
