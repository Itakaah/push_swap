/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ausmanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:15:11 by ausmanov          #+#    #+#             */
/*   Updated: 2025/11/07 18:09:09 by ausmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*find_word(char const *s, char c, size_t i)
{
	size_t	start_word;
	size_t	end_word;
	char	*res_word;

	if (!s)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	start_word = i;
	while (s[i] && s[i] != c)
		i++;
	end_word = i - 1;
	res_word = malloc(sizeof(char) * (end_word - start_word + 2));
	if (!res_word)
		return (NULL);
	i = 0;
	while (start_word <= end_word)
		res_word[i++] = s[start_word++];
	res_word[i] = '\0';
	return (res_word);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	free_tab(char **tab, size_t i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
}

char	**create_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = find_word(s, c, i);
			if (!tab[j])
			{
				free_tab(tab, j);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_len;

	if (!s)
		return (NULL);
	tab_len = count_words(s, c) + 1;
	tab = malloc(sizeof(char *) * tab_len);
	if (!tab)
		return (NULL);
	tab = create_tab(tab, s, c);
	return (tab);
}
/*
#include <stdio.h>

int main()
{
	char **res;
	size_t i;

	res = ft_split("  salut   ca  va  ?", ' ');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}
*/
