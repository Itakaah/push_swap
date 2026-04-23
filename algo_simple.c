/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

int	ft_find_min(t_stack *a)
{
	int		pos;
	int		i;
	int		val;
	t_node	*current;

	if (a->top == NULL)
		return (0);
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

void	ft_bring_to_top(t_stack *a, int pos, t_bench *bench)
{
	if (a->top == NULL)
		return ;
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (a->size - pos > 0)
		{
			rra(a, bench);
			pos++;
		}
	}
}

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	a0;
	int	a1;
	int	a2;

	if (ft_is_sorted(a))
		return ;
	a0 = a->top->value;
	a1 = a->top->next->value;
	a2 = a->top->next->next->value;
	if (a0 < a2 && a2 < a1)
	{
		rra(a, bench);
		sa(a, bench);
	}
	else if (a2 < a0 && a0 < a1)
		rra(a, bench);
	else if (a1 < a0 && a0 < a2)
		sa(a, bench);
	else if (a1 < a2 && a2 < a0)
		ra(a, bench);
	else
	{
		sa(a, bench);
		rra(a, bench);
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	if (a->size == 2 && !ft_is_sorted(a))
	{
		sa(a, bench);
		return ;
	}
	if (a->size == 3 && !ft_is_sorted(a))
	{
		sort_three(a, bench);
		return ;
	}
	while (!ft_is_sorted(a))
	{
		pos = ft_find_min(a);
		ft_bring_to_top(a, pos, bench);
		pb(a, b, bench);
	}
	while (b->top != NULL)
		pa(a, b, bench);
}
