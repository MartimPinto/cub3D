/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:42:52 by jgomes-v          #+#    #+#             */
/*   Updated: 2024/01/22 11:01:52 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_realloc_str(char *ptr, size_t new_size)
{
	char	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr)
	{
		if (ptr)
		{
			ft_strlcpy(new_ptr, ptr, new_size + 1);
			free(ptr);
		}
	}
	return (new_ptr);
}
