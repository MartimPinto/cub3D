/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:27:19 by axelc             #+#    #+#             */
/*   Updated: 2023/11/01 17:57:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lengths;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	lengths = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > dest_len)
		lengths = dest_len + src_len;
	else
		return (lengths = src_len + size);
	while (src[i] != '\0' && (dest_len + 1) < size)
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	return (lengths);
}
