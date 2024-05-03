/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:39 by achabrer          #+#    #+#             */
/*   Updated: 2023/12/11 14:26:12 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_alloc_fill(int size, char to_fill)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	res = (char *)ft_memset(res, to_fill, size);
	res[size] = '\0';
	return (res);
}
