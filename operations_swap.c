/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_swap(t_stack *s)
{
	int	tmp_val;
	int	tmp_rank;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp_val = s->top->value;
	tmp_rank = s->top->rank;
	s->top->value = s->top->next->value;
	s->top->rank = s->top->next->rank;
	s->top->next->value = tmp_val;
	s->top->next->rank = tmp_rank;
}

void	sa(t_stack *a, t_bench *bench)
{
	ft_swap(a);
	bench->sa++;
	ft_printf("sa\n");
}

void	sb(t_stack *b, t_bench *bench)
{
	ft_swap(b);
	bench->sb++;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	bench->ss++;
	ft_printf("ss\n");
}
