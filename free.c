#include "stack.h"

void	ft_free(t_stack *a, t_stack *b)
{
	t_node *next;

	while (a->top != NULL)
	{
		next = a->top->next;
		free(a->top);
		a->top = next;
	}
	while (b->top != NULL)
	{
		next = b->top->next;
		free(b->top);
		b->top = next;
	}
	free(a);
	free(b);
}