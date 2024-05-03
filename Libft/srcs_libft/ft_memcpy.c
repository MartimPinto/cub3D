/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:35:35 by axelc             #+#    #+#             */
/*   Updated: 2023/11/01 17:57:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*origin_dest;

	if (n == 0 || dest == src)
		return (dest);
	origin_dest = dest;
	while (n--)
		*((char *)dest++) = *((char *)src++);
	return (origin_dest);
}
