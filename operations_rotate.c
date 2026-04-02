#include "stack.h"

void	ra(t_stack *a)
{
	int	tmp;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->value;
	ft_pop_top(a);
	ft_push_bottom(a, tmp);
}

void	rb(t_stack *b)
{
	int	tmp;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->value;
	ft_pop_top(b);
	ft_push_bottom(b, tmp);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}