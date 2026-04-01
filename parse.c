#include "stack.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_is_valid_int(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
	}
	while (str[i])
	{
		if (!(ft_is_digit(str[i])))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

int	ft_has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	current = a->top;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->value == next->value)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}
