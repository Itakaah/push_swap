#include "stack.h"

int	ft_is_sorted(t_stack *a)
{
	t_node	*current;

	if (a->top == NULL || a->top->next == NULL)
		return (1);
	current = a->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

float	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	t_node	*i;
	t_node	*j;

	if (a->top == NULL || a->top->next == NULL)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
				mistakes += 1;
			total_pairs += 1;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / total_pairs);
}