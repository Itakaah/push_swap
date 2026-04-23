/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_rotate(t_stack *s)
{
	t_node	*bottom;
	int		tmp_val;
	int		tmp_rank;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp_val = s->top->value;
	tmp_rank = s->top->rank;
	ft_pop_top(s);
	ft_push_bottom(s, tmp_val);
	bottom = s->top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->rank = tmp_rank;
}

void	ra(t_stack *a, t_bench *bench)
{
	ft_rotate(a);
	bench->ra++;
	ft_printf("ra\n");
}

void	rb(t_stack *b, t_bench *bench)
{
	ft_rotate(b);
	bench->rb++;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rotate(a);
	ft_rotate(b);
	bench->rr++;
	ft_printf("rr\n");
}
