/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int	pos;

	while (b->top != NULL)
	{
		pos = ft_find_max(b);
		if (pos <= b->size / 2)
		{
			while (pos > 0)
			{
				rb(b, bench);
				pos--;
			}
		}
		else
		{
			while (b->size - pos > 0)
			{
				rrb(b, bench);
				pos++;
			}
		}
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
