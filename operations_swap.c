#include "stack.h"

void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = tmp;
}

void	sa(t_stack *a, t_bench *bench)
{
	ft_swap(a);
	bench->sa++;
	ft_printf("sa\n");
}

void	sb(t_stack *b, t_bench *bench)
{
	ft_swap(b);
	bench->sb++;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	bench->ss++;
	ft_printf("ss\n");
}
