NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRCS =	algo_adaptive.c \
		algo_complex.c \
		algo_medium.c \
		algo_simple.c \
		bench_utils.c \
		bench.c \
		free.c \
		main_utils.c \
		main.c \
		operations_push.c \
		operations_rotate.c \
		operations_rrotate.c \
		operations_swap.c \
		parse.c \
		stack_init.c \
		stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re