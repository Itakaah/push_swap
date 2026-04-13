#include "stack.h"

void	ft_rrotate(t_stack *s)
{
	int	value;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	value = ft_pop_bottom(s);
	ft_push_top(s, value);
}

void	rra(t_stack *a)
{
	ft_rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	ft_rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	ft_printf("rrr\n");
}
