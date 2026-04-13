#include "stack.h"

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->top == NULL)
		return ;
	ft_push_top(b, a->top->value);
	ft_pop_top(a);
	bench->pb++;
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (b->top == NULL)
		return ;
	ft_push_top(a, b->top->value);
	ft_pop_top(b);
	bench->pa++;
	ft_printf("pa\n");
}
