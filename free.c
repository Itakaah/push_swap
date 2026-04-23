/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_free(t_stack *a, t_stack *b)
{
	t_node	*next;

	while (a->top != NULL)
	{
		next = a->top->next;
		free(a->top);
		a->top = next;
	}
	while (b->top != NULL)
	{
		next = b->top->next;
		free(b->top);
		b->top = next;
	}
	free(a);
	free(b);
}
