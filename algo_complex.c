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

void	sort_complex_pass(t_stack *a, t_stack *b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((a->top->rank >> bit) & 1) == 0)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (b->top != NULL)
		pa(a, b);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;

	ft_assign_ranks(a);
	max_bits = ft_get_max_bits(a->size - 1);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		sort_complex_pass(a, b, i, size);
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		rra(a);
		i++;
	}
}
