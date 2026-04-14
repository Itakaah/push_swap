#include "stack.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
	int		flag;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	ft_init_stacks(a, b);
	flag = ft_get_flag(av);
	ft_fill_stack(a, av, ft_get_start(av), ac);
	disorder = compute_disorder(a);
	ft_run_algo(a, b, flag, &bench);
	if (ft_has_bench(ac, av))
		ft_print_bench(&bench, disorder, flag);
	ft_free(a, b);
	return (0);
}
