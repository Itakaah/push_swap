/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:25:35 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/08 19:34:44 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	if (dst_len == size)
		return (size + ft_strlen(src));
	i = dst_len;
	j = 0;
	while (i + 1 < size && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
#include <stdio.h>
int main()
{
	char a[30] = "abcd";
	ft_strlcat(a, "SALUT CA VA ?", 9);
	printf("%s", a);
}
*/
