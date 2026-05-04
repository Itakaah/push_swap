/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	sort_complex_pass(t_stack *a, t_stack *b, int bit, t_bench *bench)
{
	int	j;
	int	size;

	size = a->size;
	j = 0;
	while (j < size)
	{
		if (((a->top->rank >> bit) & 1) == 0)
			pb(a, b, bench);
		else
			ra(a, bench);
		j++;
	}
	while (b->top != NULL)
		pa(a, b, bench);
}

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_bits;
	int	i;

	if (ft_is_sorted(a))
		return ;
	if (ft_is_reverse_sorted(a))
	{
		sort_simple(a, b, bench);
		return ;
	}
	ft_assign_ranks(a);
	max_bits = ft_get_max_bits(a->size - 1);
	i = 0;
	while (i < max_bits)
	{
		if (ft_is_sorted(a))
			break ;
		sort_complex_pass(a, b, i, bench);
		i++;
	}
}
