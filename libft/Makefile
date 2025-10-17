CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME	= libft.a
SRCS    = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c  \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_atoi.c \


OBJS    = $(SRCS:%.c=%.o)
HEADER	= -Ilibft.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar	rcs	$(NAME)	$(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY:	all	clean	fclean	re
