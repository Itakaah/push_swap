/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:53:05 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/08 18:32:11 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	to_upper(void *content)
{
	char *str = content;
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int	main()
{
	t_list *node1 = ft_lstnew(ft_strdup("hello"));
	t_list *node2 = ft_lstnew(ft_strdup("world"));
        t_list *node3 = ft_lstnew(ft_strdup("42"));

	node1->next = node2;
	node2->next = node3;

	ft_lstiter(node1, to_upper);

	t_list *tmp = node1;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&node1, free);
}
*/
