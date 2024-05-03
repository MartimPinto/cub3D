/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:34:30 by mcarneir          #+#    #+#             */
/*   Updated: 2024/05/02 10:01:11 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i])) || ft_isalpha(str[i]))
			return (false);
		i++;
	}
	return (true);
}
