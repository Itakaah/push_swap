/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:05:04 by ausmanov          #+#    #+#             */
/*   Updated: 2026/04/20 12:00:00 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	ft_print_disorder(float disorder)
{
	int		total;
	int		dec;
	char	*str;

	total = (int)(disorder * 10000 + 0.5f);
	dec = total % 100;
	write(2, "[bench] disorder: ", 18);
	str = ft_itoa(total / 100);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, ".", 1);
	if (dec < 10)
		write(2, "0", 1);
	str = ft_itoa(dec);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, "%\n", 2);
}

void	ft_print_strategy(int flag, float disorder)
{
	write(2, "[bench] strategy: ", 18);
	if (flag == 1)
		write(2, "Simple / O(n\xc2\xb2)\n",
			sizeof("Simple / O(n\xc2\xb2)\n") - 1);
	else if (flag == 2)
		write(2, "Medium / O(n\xe2\x88\x9an)\n",
			sizeof("Medium / O(n\xe2\x88\x9an)\n") - 1);
	else if (flag == 3)
		write(2, "Complex / O(n log n)\n",
			sizeof("Complex / O(n log n)\n") - 1);
	else if (disorder < 0.2)
		write(2, "Adaptive / O(n\xc2\xb2)\n",
			sizeof("Adaptive / O(n\xc2\xb2)\n") - 1);
	else if (disorder < 0.5)
		write(2, "Adaptive / O(n\xe2\x88\x9an)\n",
			sizeof("Adaptive / O(n\xe2\x88\x9an)\n") - 1);
	else
		write(2, "Adaptive / O(n log n)\n",
			sizeof("Adaptive / O(n log n)\n") - 1);
}

void	ft_print_total_ops(t_bench *bench)
{
	int		total;
	char	*str;

	total = bench->sa + bench->sb + bench->ss;
	total += bench->pa + bench->pb;
	total += bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr;
	write(2, "[bench] total_ops: ", 19);
	str = ft_itoa(total);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
}

void	ft_print_op_counts1(t_bench *bench)
{
	char	*str;

	write(2, "[bench] sa: ", 12);
	str = ft_itoa(bench->sa);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " sb: ", 5);
	str = ft_itoa(bench->sb);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " ss: ", 5);
	str = ft_itoa(bench->ss);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " pa: ", 5);
	str = ft_itoa(bench->pa);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " pb: ", 5);
	str = ft_itoa(bench->pb);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, "\n", 1);
}

void	ft_print_op_counts2(t_bench *bench)
{
	char	*str;

	write(2, "[bench] ra: ", 12);
	str = ft_itoa(bench->ra);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " rb: ", 5);
	str = ft_itoa(bench->rb);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " rr: ", 5);
	str = ft_itoa(bench->rr);
	write(2, str, ft_strlen(str));
	free(str);
}
