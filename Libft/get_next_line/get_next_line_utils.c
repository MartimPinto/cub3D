/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:13:46 by axelchab          #+#    #+#             */
/*   Updated: 2023/11/01 17:59:19 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strchri(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

int	ft_slen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_realjoin(char *stash, char *buf, char *join)
{
	char	*origin_join;

	origin_join = join;
	while (*stash)
		*join++ = *stash++;
	while (*buf)
		*join++ = *buf++;
	*join = '\0';
	return (origin_join);
}

char	*ft_strjoini(char *stash, char *buf)
{
	char	*join;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char));
		*stash = '\0';
	}
	if (!stash || !buf)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_slen(stash)+ ft_slen(buf) + 1));
	if (!join)
		return (NULL);
	join = ft_realjoin(stash, buf, join);
	free (stash);
	return (join);
}
