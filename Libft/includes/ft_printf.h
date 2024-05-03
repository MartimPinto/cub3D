/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:33:33 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/01 18:03:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		check_print(char c, va_list args);
int		ft_printstr(const char *s);
int		ft_printchar(int c);
int		ft_printnb(int nb);
int		ft_printptr(unsigned long long ptr);
int		ft_printhexa(unsigned int nb);
int		ft_printhexa_up(unsigned int nb);
int		ft_printunsigned(unsigned int nb);
int		size_hexa(unsigned int nb);

#endif
