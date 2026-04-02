#include "stack.h"

int	ft_find_min(t_stack *a)
{
	int		pos;
	int		i;
	int		val;
	t_node	*current;

	if (a->top == NULL)
		return 0;
	pos = 0;
	i = 0;
	val = a->top->value;
	current = a->top;
	while (current != NULL)
	{
		if (current->value < val)
		{
			val = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	ft_bring_to_top(t_stack *a, int pos)
{
	if (a->top == NULL)
		return ;
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	} else {
		while (a->size - pos > 0)
		{
			rra(a);
			pos++;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	pos;

	while (!ft_is_sorted(a))
	{
		pos = ft_find_min(a);
		ft_bring_to_top(a, pos);
		pb(a, b);
	}
	while (b->top != NULL)
	{
		pa(a, b);
	}
}