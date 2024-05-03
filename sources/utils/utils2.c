/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:35:24 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/22 15:19:42 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	initialize_chars(char **chars)
{
	chars[0] = "NO";
	chars[1] = "SO";
	chars[2] = "WE";
	chars[3] = "EA";
	chars[4] = "F";
	chars[5] = "C";
	chars[6] = NULL;
}

bool	check_player(char **map)
{
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				p += 1;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (false);
	else
		return (true);
}

void	replace_map_space(void)
{
	int		i;
	int		j;
	char	**map;

	map = game()->map_info->arr;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = WALL;
		}
	}
}

int	get_row_size(int y)
{
	if (!game()->map[y])
		return (0);
	return (ft_strlen(game()->map[y]));
}

int	get_col_size(void)
{
	int	size;

	size = 0;
	while (game()->map[size])
		size++;
	return (size);
}
