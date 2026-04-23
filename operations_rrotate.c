/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_rrotate(t_stack *s)
{
	t_node	*bottom;
	int		value;
	int		rank;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	bottom = s->top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	value = bottom->value;
	rank = bottom->rank;
	if (bottom->prev)
		bottom->prev->next = NULL;
	free(bottom);
	s->size--;
	ft_push_top(s, value);
	s->top->rank = rank;
}

void	rra(t_stack *a, t_bench *bench)
{
	ft_rrotate(a);
	bench->rra++;
	ft_printf("rra\n");
}

void	rrb(t_stack *b, t_bench *bench)
{
	ft_rrotate(b);
	bench->rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rrotate(a);
	ft_rrotate(b);
	bench->rrr++;
	ft_printf("rrr\n");
}
