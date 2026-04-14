#include "stack.h"

void	ft_init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

int	ft_get_flag(char **av)
{
	int	i;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
	{
		if (ft_strncmp(av[i], "--simple", 8) == 0)
			return (1);
		if (ft_strncmp(av[i], "--medium", 8) == 0)
			return (2);
		if (ft_strncmp(av[i], "--complex", 9) == 0)
			return (3);
		i++;
	}
	return (0);
}

int	ft_get_start(char **av)
{
	int	i;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
		i++;
	return (i);
}

void	ft_fill_stack(t_stack *a, char **av, int start, int ac)
{
	int	i;

	i = start;
	while (i < ac)
	{
		if (ft_is_valid_int(av[i]))
		{
			ft_push_bottom(a, ft_atol(av[i]));
		}
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if (ft_has_duplicates(a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_run_algo(t_stack *a, t_stack *b, int flag, t_bench *bench)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (flag == 0)
		sort_adaptive(a, b, bench, disorder);
	else if (flag == 1)
		sort_simple(a, b, bench);
	else if (flag == 2)
		sort_medium(a, b, bench);
	else if (flag == 3)
		sort_complex(a, b, bench);
}
