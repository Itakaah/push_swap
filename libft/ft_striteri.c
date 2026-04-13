/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:03:19 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/07 21:16:33 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	to_upper(unsigned int i, char *c)
{
	i++;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

#include <stdio.h>

int main()
{
	char s[] = "Hello World";
	ft_striteri(s, to_upper);
	printf("%s\n", s);
	return (0);
}
*/
