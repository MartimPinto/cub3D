/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:21:21 by axelc             #+#    #+#             */
/*   Updated: 2023/11/01 17:57:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*origin;

	cpy = (char *)malloc(sizeof(*cpy) * (ft_strlen(s) + 1));
	if (!cpy)
		return (0);
	origin = cpy;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (origin);
}
