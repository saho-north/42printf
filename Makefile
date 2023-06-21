NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
DEBUG	= -fsanitize=address -g
AR		= ar
ARFLAGS = rc
SRCS	= ft_printf.c \
		ft_putchar_fd_count.c \
		ft_putnbr_fd_base_count.c \
		ft_putptr_fd_count.c \
		ft_putstr_fd_count.c \
		ft_strlen.c
OBJS 	= $(SRCS:.c=.o)
INCS	= ft_printf.h
BONUS_SRCS	= ft_printf_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	= ft_printf_bonus.h

ALL_OBJS 	= $(OBJS)
ifdef ADD
ALL_OBJS	+= $(BONUS_OBJS)
endif

$(NAME): $(ALL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	make ADD=1

test: $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) main.c $^ -o test_executable
	./test_executable

.PHONY: all clean fclean re bonus test
