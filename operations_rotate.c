#include "stack.h"

void	ft_rotate(t_stack *s)
{
	int	tmp;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = s->top->value;
	ft_pop_top(s);
	ft_push_bottom(s, tmp);
}

void	ra(t_stack *a, t_bench *bench)
{
	ft_rotate(a);
	bench->ra++;
	ft_printf("ra\n");
}

void	rb(t_stack *b, t_bench *bench)
{
	ft_rotate(b);
	bench->rb++;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rotate(a);
	ft_rotate(b);
	bench->rr++;
	ft_printf("rr\n");
}
