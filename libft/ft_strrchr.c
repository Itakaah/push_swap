/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:20:56 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/08 19:05:38 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;

	res = NULL;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (res)
		return ((char *)res);
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char *test = ft_strrchr("Hewllwojknsiowne", '@');

	if (test)
		printf("%s\n", test);
	else
		printf("Character not found\n");
}
*/
