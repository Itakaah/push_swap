/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

static int	ft_setup(t_stack **a, t_stack **b, t_bench *bench)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		return (1);
	}
	ft_memset(bench, 0, sizeof(t_bench));
	ft_init_stacks(*a, *b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
	int		flag;

	if (ac == 1)
		return (0);
	if (ft_setup(&a, &b, &bench))
		return (1);
	flag = ft_get_flag(av);
	if (flag == -1 || ft_fill_stack(a, av, ft_get_start(av), ac))
	{
		ft_free(a, b);
		return (1);
	}
	disorder = compute_disorder(a);
	ft_run_algo(a, b, flag, &bench);
	if (ft_has_bench(ac, av))
		ft_print_bench(&bench, disorder, flag);
	ft_free(a, b);
	return (0);
}
