/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:01:50 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/25 19:21:27 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	size_t			i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>

int main()
{
	int *arr = ft_calloc(9, sizeof(int));
	int i = 0;
	if (!arr)
	{
		printf("NULL");
		return (0);
	}
	while (i < 9)
	{
		printf("%d ", arr[i]);
		i++;
	}
	free(arr);
}
*/
