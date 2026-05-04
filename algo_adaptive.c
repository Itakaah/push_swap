/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench, float disorder)
{
	if (a->size <= 5 || disorder < 0.2 || ft_is_reverse_sorted(a))
		sort_simple(a, b, bench);
	else if (disorder < 0.5 && a->size <= 50)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}
