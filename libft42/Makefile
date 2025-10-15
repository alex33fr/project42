CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = srcs/ft_putchar.c \
	  srcs/ft_swap.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strlen.c \
	  srcs/ft_strcmp.c \
OBJS    = $(SRCS:%.c=%.o)
OUT     = libft.a
HEADER	= -Iincludes/ft.h
all: $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OUT): $(OBJS)
	-ar rcs $(OUT) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all
