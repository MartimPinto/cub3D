/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:32:56 by axel              #+#    #+#             */
/*   Updated: 2023/11/01 17:57:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	counts;
	int	i;

	counts = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counts++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counts);
}

static char	*word_dup(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;

	j = 0;
	split = (char **)malloc(sizeof (char *) * (ft_countwords(s, c) + 1));
	if (!split || !s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			split[j] = word_dup(s, c);
			while (*s && *s != c)
				s++;
			j++;
		}
		else
			s++;
	}
	split[j] = 0;
	return (split);
}
