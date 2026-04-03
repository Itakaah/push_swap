#include "stack.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_max;
	int	pushed;

	if (a->top == NULL)
		return ;
	ft_assign_ranks(a);
	chunk_size = ft_sqrt(a->size);
	chunk_max = chunk_size;
	while (a->top != NULL)
	{
		pushed = 0;
		while (pushed < chunk_size && a->top != NULL)
		{
			if (a->top->rank < chunk_max)
			{
				pb(a, b);
				pushed++;
			} else {
				ra(a);
			}
		}
		chunk_max += chunk_size;
	}
	while (b->top != NULL)
	{
		ft_bring_to_top(b, ft_find_max(b));
		pa(a, b);
	}
}