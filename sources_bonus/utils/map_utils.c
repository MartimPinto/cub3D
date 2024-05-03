/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:50:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/29 16:16:27 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == PLAYER);
}

bool	is_floor(char c)
{
	return (c == FLOOR);
}

bool	is_wall(char c)
{
	return (c == WALL);
}

bool	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_row(char *line)
{
	int	i;

	i = -1;
	if (line[0] == '\n')
		return (false);
	while (line[++i])
	{
		if (ft_isalnum(line[i]) || line[i] == ' ' || line[i] == '\n')
			continue ;
		else
			return (false);
	}
	return (true);
}
