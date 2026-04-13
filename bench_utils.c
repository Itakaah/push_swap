#include "stack.h"

void	ft_print_disorder(float disorder)
{
	char	*str;

	write(2, "[bench] disorder: ", 18);
	str = ft_itoa((int)(disorder * 100));
	write(2, str, ft_strlen(str));
	write(2, "%\n", 2);
	free(str);
}

void	ft_print_strategy(int flag)
{
	write(2, "[bench] strategy: ", sizeof("[bench] strategy: ") - 1);
	if (flag == 0)
		write(2, "Adaptive / O(n log n)\n",
			sizeof("Adaptive / O(n log n)\n") - 1);
	else if (flag == 1)
		write(2, "Simple / O(n\xc2\xb2)\n",
			sizeof("Simple / O(n\xc2\xb2)\n") - 1);
	else if (flag == 2)
		write(2, "Medium / O(n\xe2\x88\x9an)\n",
			sizeof("Medium / O(n\xe2\x88\x9an)\n") - 1);
	else if (flag == 3)
		write(2, "Complex / O(n log n)\n",
			sizeof("Complex / O(n log n)\n") - 1);
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
	write(2, " rra: ", 6);
	str = ft_itoa(bench->rra);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " rrb: ", 6);
	str = ft_itoa(bench->rrb);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, " rrr: ", 6);
	str = ft_itoa(bench->rrr);
	write(2, str, ft_strlen(str));
	free(str);
	write(2, "\n", 1);
}