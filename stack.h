/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_chunk
{
	int	max;
	int	size;
}	t_chunk;

t_node	*ft_new_node(int value);
void	ft_push_top(t_stack *a, int value);
void	ft_pop_top(t_stack *a);
void	ft_push_bottom(t_stack *a, int value);
int		ft_pop_bottom(t_stack *a);
int		ft_is_sorted(t_stack *a);
int		ft_is_reverse_sorted(t_stack *a);
float	compute_disorder(t_stack *a);
void	ft_assign_ranks(t_stack *a);
int		ft_sqrt(int n);
int		ft_get_max_bits(int max);
int		ft_find_min(t_stack *a);
int		ft_find_max(t_stack *a);
void	ft_bring_to_top(t_stack *a, int pos, t_bench *bench);
int		ft_is_valid_int(char *str);
int		ft_fill_from_split(t_stack *a, char *arg);
int		ft_has_duplicates(t_stack *a);
long	ft_atol(const char *str);
void	sa(t_stack *a, t_bench *bench);
void	sb(t_stack *b, t_bench *bench);
void	ss(t_stack *a, t_stack *b, t_bench *bench);
void	pa(t_stack *a, t_stack *b, t_bench *bench);
void	pb(t_stack *a, t_stack *b, t_bench *bench);
void	ra(t_stack *a, t_bench *bench);
void	rb(t_stack *b, t_bench *bench);
void	rr(t_stack *a, t_stack *b, t_bench *bench);
void	rra(t_stack *a, t_bench *bench);
void	rrb(t_stack *b, t_bench *bench);
void	rrr(t_stack *a, t_stack *b, t_bench *bench);
void	sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void	sort_medium_push(t_stack *a, t_stack *b, t_chunk *c, t_bench *bench);
void	sort_medium_restack(t_stack *a, t_stack *b, t_bench *bench);
void	sort_medium(t_stack *a, t_stack *b, t_bench *bench);
void	sort_complex_pass(t_stack *a, t_stack *b, int bit, t_bench *bench);
void	sort_complex(t_stack *a, t_stack *b, t_bench *bench);
void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench, float disorder);
void	ft_init_stacks(t_stack *a, t_stack *b);
int		ft_get_flag(char **av);
int		ft_get_start(char **av);
int		ft_fill_stack(t_stack *a, char **av, int start, int ac);
void	ft_run_algo(t_stack *a, t_stack *b, int flag, t_bench *bench);
void	ft_free_tab(char **tab);
void	ft_free(t_stack *a, t_stack *b);
void	ft_print_disorder(float disorder);
void	ft_print_strategy(int flag, float disorder);
void	ft_print_total_ops(t_bench *bench);
void	ft_print_op_counts1(t_bench *bench);
void	ft_print_op_counts2(t_bench *bench);
void	ft_print_op_counts3(t_bench *bench);
void	ft_print_op_counts(t_bench *bench);
void	ft_print_bench(t_bench *bench, float disorder, int flag);
int		ft_has_bench(int ac, char **av);

#endif