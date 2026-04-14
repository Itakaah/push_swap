#include "stack.h"

void	ft_print_op_counts3(t_bench *bench)
{
	char	*str;

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

void	ft_print_op_counts(t_bench *bench)
{
	ft_print_op_counts1(bench);
	ft_print_op_counts2(bench);
	ft_print_op_counts3(bench);
}

void	ft_print_bench(t_bench *bench, float disorder, int flag)
{
	ft_print_disorder(disorder);
	ft_print_strategy(flag, disorder);
	ft_print_total_ops(bench);
	ft_print_op_counts(bench);
}

int	ft_has_bench(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[i], "--bench", 7) == 0)
			return (1);
		i++;
	}
	return (0);
}
