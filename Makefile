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

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re