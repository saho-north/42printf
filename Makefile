NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
DEBUG	= -fsanitize=address -g
AR		= ar
ARFLAGS = rc
SRCS	= ft_printf.c \
		ft_putchar_count.c \
		ft_puthex_count.c \
		ft_putnbr_base_count.c \
		ft_putptr_count.c \
		ft_putstr_count.c \
		ft_strlen.c
OBJS 	= $(SRCS:.c=.o)
INCS	= ft_printf.h

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) main.c $^ -o test_executable
	./test_executable
	make clean
	rm -rf test_executable test_executable.dSYM

.PHONY: all clean fclean re test
