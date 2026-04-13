/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:15:12 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/08 16:05:13 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("world");
	t_list *node2 = ft_lstnew("hello");

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);

	printf("%s\n", (char *)list->content);
	printf("%s\n", (char *)list->next->content);
}
*/
