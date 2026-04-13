/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:12:08 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/17 11:19:53 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("world");
	t_list *node2 = ft_lstnew("hello");

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);

	t_list *last = ft_lstlast(list);
	printf("%s\n", (char *)last->content);
}
*/
