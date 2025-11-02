CC      = cc

CFLAGS  = -Wall -Wextra -Werror -I.

AR	= ar rcs

NAME	= libftprintf.a

SRCS    = ft_printf.c \
		tools/ft_print_char.c \
		tools/ft_print_string.c \
		tools/ft_print_int.c \

OBJS    = $(SRCS:%.c=%.o)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

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
