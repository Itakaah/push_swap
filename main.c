#include "stack.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
	int		flag;
	int		start;
	int		is_bench;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	ft_init_stacks(a, b);
	flag = ft_get_flag(av);
	start = ft_get_start(av);
	ft_fill_stack(a, av, start, ac);
	disorder = compute_disorder(a);
	ft_run_algo(a, b, flag, disorder, &bench);
	is_bench = ft_has_bench(ac, av);
	if (is_bench)
		ft_print_bench(&bench, disorder, flag);
	ft_free(a, b);
	return (0);
}
