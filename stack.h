#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct s_node
{
    int				value;
	int				rank;
    struct s_node	*next;
    struct s_node	*prev;
}   t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}   t_stack;

t_node	*ft_new_node(int value);
void	ft_push_top(t_stack *a, int value);
int		ft_is_valid_int(char *str);
int		ft_has_duplicates(t_stack *a);
void	ft_pop_top(t_stack *a);
void	ft_push_bottom(t_stack *a, int value);
int		ft_pop_bottom(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *a);
float	compute_disorder(t_stack *a);
int		ft_find_min(t_stack *a);
void	ft_bring_to_top(t_stack *a, int pos);
void	sort_simple(t_stack *a, t_stack *b);
void	ft_assign_ranks(t_stack *a);
int		ft_sqrt(int n);
int	ft_find_max(t_stack *a);

#endif
