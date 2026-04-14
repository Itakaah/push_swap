#include "stack.h"

void	sort_medium_push(t_stack *a, t_stack *b, t_chunk *chunk, t_bench *bench)
{
	int	pushed;

	pushed = 0;
	while (pushed < chunk->size && a->top != NULL)
	{
		if (a->top->rank < chunk->max)
		{
			pb(a, b, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}

void	sort_medium_restack(t_stack *a, t_stack *b, t_bench *bench)
{
	while (b->top != NULL)
	{
		ft_bring_to_top(b, ft_find_max(b), bench);
		pa(a, b, bench);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
	t_chunk	chunk;

	if (a->top == NULL)
		return ;
	ft_assign_ranks(a);
	chunk.size = ft_sqrt(a->size);
	chunk.max = chunk.size;
	while (a->top != NULL)
	{
		sort_medium_push(a, b, &chunk, bench);
		chunk.max += chunk.size;
	}
	sort_medium_restack(a, b, bench);
}
