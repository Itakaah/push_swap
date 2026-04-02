#include "stack.h"

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == NULL)
		return ;
	ft_push_top(b, a->top->value);
	ft_pop_top(a);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == NULL)
		return ;
	ft_push_top(a, b->top->value);
	ft_pop_top(b);
}