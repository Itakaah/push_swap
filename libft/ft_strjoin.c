/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:18:43 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/24 17:20:12 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	total_len;

	total_len = 0;
	if (s1)
		total_len += ft_strlen(s1);
	if (s2)
		total_len += ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = 0;
	return (res);
}
/*
#include <stdio.h>

int main()
{
	char *str1 = "Hello";
	char *str2 = "World";
	char *res = ft_strjoin(str1, str2);
	char *res2 = ft_strjoin(str1, "");
	char *res3 = ft_strjoin("", str2);
	
	printf("%s\n %s\n %s\n", res, res2, res3);
	free(res);
	free(res2);
	free(res3);
}
*/
