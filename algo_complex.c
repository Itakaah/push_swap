#include "stack.h"

int	ft_get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	ft_assign_ranks(a);
	max_bits = ft_get_max_bits(a->size - 1);
	i = 0;
	size = a->size;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->rank >> i) & 1) == 0)
				ra(a);
			else if (((a->top->rank >> i) & 1) == 1)
				pb(a, b);
			j++;
		}
		while (b->top != NULL)
		{
			pa(a, b);
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		rra(a);
		i++;
	}
}