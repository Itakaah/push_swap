#include "stack.h"

void	sort_medium_push(t_stack *a, t_stack *b, int chunk_max, int chunk_size)
{
	int	pushed;

	pushed = 0;
	while (pushed < chunk_size && a->top != NULL)
	{
		if (a->top->rank < chunk_max)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	sort_medium_restack(t_stack *a, t_stack *b)
{
	while (b->top != NULL)
	{
		ft_bring_to_top(b, ft_find_max(b));
		pa(a, b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_max;

	if (a->top == NULL)
		return ;
	ft_assign_ranks(a);
	chunk_size = ft_sqrt(a->size);
	chunk_max = chunk_size;
	while (a->top != NULL)
	{
		sort_medium_push(a, b, chunk_max, chunk_size);
		chunk_max += chunk_size;
	}
	sort_medium_restack(a, b);
}
