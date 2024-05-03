/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:53:22 by axelchab          #+#    #+#             */
/*   Updated: 2023/11/01 17:59:40 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	size_hexa(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		size++;
	}
	return (size);
}

int	ft_printhexa(unsigned int nb)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = size_hexa(nb);
	if (nb >= 16)
	{
		ft_printhexa(nb / 16);
		nb = nb % 16;
	}
	ft_printchar(base[nb]);
	return (count);
}

int	ft_printhexa_up(unsigned int nb)
{
	int		count;
	char	*base;

	count = size_hexa(nb);
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_printhexa_up(nb / 16);
		nb = nb % 16;
	}
	ft_printchar(base[nb]);
	return (count);
}
