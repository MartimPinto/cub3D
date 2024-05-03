/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:28:26 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/01 17:59:40 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	sizeptr(unsigned long long ptr)
{
	int	size;

	if (!ptr)
		return (0);
	size = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		size++;
	}
	return (size);
}

static void	ft_putptr(unsigned long long ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ptr %= 16;
	}
	ft_putchar_fd(base[ptr], 1);
}

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 2 + sizeptr(ptr);
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_putptr(ptr);
	return (count);
}
