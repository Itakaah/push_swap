#include "stack.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_push_top(t_stack *a, int value)
{
	t_node *new_node;

	new_node = ft_new_node(value);
	if (!new_node)
		return ;
	new_node->next = a->top;
	if (a->top != NULL)
		a->top->prev = new_node;
	a->top = new_node;
	a->size += 1;
}

void	ft_pop_top(t_stack *a)
{
	t_node	*tmp;

	if (a->top == NULL)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	free(tmp);
	a->size--;
	if (a->top != NULL)
		a->top->prev = NULL;
}

void	ft_push_bottom(t_stack *a, int value)
{
	t_node	*current;
	t_node	*new_node;

	if (a->top == NULL)
		return ;
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	new_node = ft_new_node(value);
	if (!new_node)
		return ;
	current->next = new_node;
	new_node->prev = current;
	a->size++;
}

int	ft_pop_bottom(t_stack *a)
{
	t_node	*current;
	int	res;

	if (a->top == NULL)
		return (0);
	if (a->top->next == NULL)
	{
		res = a->top->value;
		free(a->top);
		a->top = NULL;
		a->size--;
		return (res);
	}
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	res = current->value;
	free(current);
	a->size--;
	return (res);
}