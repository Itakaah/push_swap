/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:32:30 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/17 11:27:33 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("world");
	t_list *node2 = ft_lstnew("hello");
	 t_list *node3 = ft_lstnew("42");

	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node1);
	ft_lstadd_back(&list, node3);

	printf("%s\n", (char *)ft_lstlast(list)->content);
}
*/
