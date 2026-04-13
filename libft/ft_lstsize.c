/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:59:26 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/17 11:19:23 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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

	printf("%d\n", ft_lstsize(list));
}
*/
