#include "stack.h"

void	sort_nearly_sorted(t_stack *a, t_bench *bench)
{
	while (!ft_is_sorted(a))
	{
		if (a->top->value > a->top->next->value)
			sa(a, bench);
		else
			ra(a, bench);
	}
}

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench, float disorder)
{
	if (disorder < 0.2)
		sort_nearly_sorted(a, bench);
	else if (disorder < 0.5)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}
