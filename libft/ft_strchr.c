/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:59:11 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/07 22:25:55 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char *res = ft_strchr("Hello", 'w');
	if (res)
		printf("%s\n", res);
	else
		printf("Character not found\n");

	printf("%s\n", ft_strchr("Hello", 'H'));
	printf("%s\n", ft_strchr("Hello", 'o'));
	printf("%s\n", ft_strchr("Hello", '\0'));
}
*/
