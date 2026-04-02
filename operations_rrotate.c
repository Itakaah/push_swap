#include "stack.h"

void	rra(t_stack *a)
{
	int	value;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	value = ft_pop_bottom(a);
	ft_push_top(a, value);
}

void	rrb(t_stack *b)
{
	int	value;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	value = ft_pop_bottom(b);
	ft_push_top(b, value);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}