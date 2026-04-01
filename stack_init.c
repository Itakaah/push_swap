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