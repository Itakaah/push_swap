#include "stack.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}