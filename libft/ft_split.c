/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:16:19 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/26 11:19:09 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

static void	ft_input_split(char **tab_split, char const *s, char c)
{
	size_t	i;
	size_t	t;
	size_t	start;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			tab_split[t] = ft_substr(s, start, i - start);
			t++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab_split;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_word(s, c);
	tab_split = ft_calloc(nb_words + 1, sizeof(char *));
	if (!tab_split)
		return (NULL);
	ft_input_split(tab_split, s, c);
	return (tab_split);
}
