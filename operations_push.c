/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->top == NULL)
		return ;
	ft_push_top(b, a->top->value);
	b->top->rank = a->top->rank;
	ft_pop_top(a);
	bench->pb++;
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (b->top == NULL)
		return ;
	ft_push_top(a, b->top->value);
	a->top->rank = b->top->rank;
	ft_pop_top(b);
	bench->pa++;
	ft_printf("pa\n");
}
