#include "stack.h"

void	sort_nearly_sorted(t_stack *a)
{
	while (!ft_is_sorted(a))
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		else
			ra(a);
	}
}

void	sort_adaptive(t_stack *a, t_stack *b, float disorder)
{
	if (disorder < 0.2)
		sort_nearly_sorted(a);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}