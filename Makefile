CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
DEBUG	= -fsanitize=address -g
AR		= ar
ARFLAGS = rc
NAME	= libftprintf.a
SRCS	= *.c
OBJS 	= $(SRCS:.c=.o)
INCS	= *.h
BONUS_SRCS	= test_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	=
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

test: $(NAME)
	$(CC) $(CFLAGS) $(DEBUG) main.c -L. -lftprintf -o test_executable

.PHONY: all clean fclean re bonus test
