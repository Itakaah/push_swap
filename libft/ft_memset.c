/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:46:50 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/07 22:24:42 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	b;

	tmp = (unsigned char *)s;
	b = (unsigned char)c;
	while (n > 0)
	{
		*tmp = b;
		n--;
		tmp++;
	}
	return (s);
}
