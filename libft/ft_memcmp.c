/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:33:14 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/07 22:23:42 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmps1;
	const unsigned char	*tmps2;
	size_t				i;

	tmps1 = (const unsigned char *)s1;
	tmps2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmps1[i] != tmps2[i])
			return (tmps1[i] - tmps2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char s1[] = "Hello";
	char s2[] = "Hola";
	char s3[] = "Hello";

	printf("%d\n", ft_memcmp(s1, s2, 5));
	printf("%d\n", ft_memcmp(s1, s3, 5));
}
*/
