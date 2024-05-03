/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:11 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/01 17:59:40 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_print(char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = ft_printchar(va_arg(args, int));
	if (c == 's')
		bytes = ft_printstr(va_arg(args, const char *));
	if (c == 'd' || c == 'i')
		bytes = ft_printnb(va_arg(args, int));
	if (c == 'u')
		bytes = ft_printunsigned(va_arg(args, unsigned int));
	if (c == 'p')
		bytes = ft_printptr(va_arg(args, unsigned long long));
	if (c == 'x')
		bytes = ft_printhexa(va_arg(args, unsigned int));
	if (c == 'X')
		bytes = ft_printhexa_up(va_arg(args, unsigned int));
	if (c == '%')
		bytes = write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	va_start(args, format);
	bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			bytes += check_print(*(format + 1), args);
			format++;
		}
		else
		{
			write(1, format, 1);
			bytes++;
		}
		format++;
	}
	va_end(args);
	return (bytes);
}
