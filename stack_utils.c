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

void	ft_assign_ranks(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	if (a->top == NULL)
		return ;
	current = a->top;
	while (current != NULL)
	{
		current->rank = 0;
		next = a->top;
		while (next != NULL)
		{
			if (next->value < current->value)
				current->rank += 1;
			next = next->next;
		}
		current = current->next;
	}
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int	ft_find_max(t_stack *a)
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
		if (current->value > val)
		{
			val = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}