#include "stack.h"

void	ft_init_stacks(t_stack *a, t_stack *b)
{
    a->top = NULL;
    a->size = 0;
    b->top = NULL;
    b->size = 0;
}

int		ft_get_flag(char **av)
{
	int	flag;

	flag = 0;
	if (av[1][0] == '-' && av[1][1] == '-')
	{
		if (ft_strncmp(av[1], "--simple", 8) == 0)
			flag = 1;
		else if (ft_strncmp(av[1], "--medium", 8) == 0)
			flag = 2;
		else if (ft_strncmp(av[1], "--complex", 9) == 0)
			flag = 3;
		else
			flag = 0;
	}
	return (flag);
}

int		ft_get_start(char **av)
{
	int	start;

	start = 0;
	if (av[1][0] == '-' && av[1][1] == '-')
		start = 2;
	else
		start = 1;
	return (start);
}

void	ft_fill_stack(t_stack *a, char **av, int start, int ac)
{
	int	i;

	i = start;
	while (i < ac)
	{
		if (ft_is_valid_int(av[i]))
		{
			ft_push_bottom(a, ft_atoi(av[i]));
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

void	ft_run_algo(t_stack *a, t_stack *b, int flag, float disorder, t_bench *bench)
{
	if (flag == 0)
		sort_adaptive(a, b, bench, disorder);
	else if (flag == 1)
		sort_simple(a, b, bench);
	else if (flag == 2)
		sort_medium(a, b, bench);
	else if (flag == 3)
		sort_complex(a, b, bench);
}
