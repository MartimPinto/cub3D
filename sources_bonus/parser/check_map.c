/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:50:56 by Axel              #+#    #+#             */
/*   Updated: 2024/04/18 16:27:21 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	only_ones(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
	}
	return (true);
}

static bool	closed_map_algo(char *curr_row, char *top_row, char *bott_row,
		int i)
{
	size_t	j;

	j = -1;
	while (curr_row[++j])
	{
		if (curr_row[0] != '1' || curr_row[ft_strlen(curr_row) - 1] != '1')
		{
			print_map((t_pos){i, j});
			return (false);
		}
		if (top_row && ft_strlen(curr_row) > ft_strlen(top_row)
			&& j > ft_strlen(top_row) - 1 && curr_row[j] != '1')
		{
			print_map((t_pos){i, j});
			return (false);
		}
		if (bott_row && ft_strlen(curr_row) > ft_strlen(bott_row)
			&& j > ft_strlen(bott_row) - 1 && curr_row[j] != '1')
		{
			print_map((t_pos){i, j});
			return (false);
		}
	}
	return (true);
}

static bool	is_closed_map(char **map, size_t i)
{
	char	*curr_row;
	char	*top_row;
	char	*bott_row;

	top_row = NULL;
	bott_row = NULL;
	curr_row = map[i];
	if (i > 0)
		top_row = map[i - 1];
	if (i < get_matrix_len(map))
		bott_row = map[i + 1];
	return (closed_map_algo(curr_row, top_row, bott_row, i));
}

static bool	has_invalid_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_wall(str[i]) || is_player(str[i]) || is_floor(str[i])
			|| str[i] == ' ')
			continue ;
		else
			return (true);
	}
	return (false);
}

void	check_map(char **map)
{
	size_t	i;

	i = 0;
	if (map[0] == NULL)
		exit_error(EMPTY_LINE, INVALID_MAP);
	if (!check_player(map))
		exit_error(INVALID_PLAYER, INVALID_MAP);
	while (map[i])
	{
		if (!only_ones(map[i]) && (i == 0 || i == get_matrix_len(map) - 1))
			exit_error(INVALID_WALLS, INVALID_MAP);
		if (map[i][0] == '\0')
			exit_error(EMPTY_LINE, INVALID_MAP);
		if (!is_closed_map(map, i))
			exit_error(INVALID_WALLS, INVALID_MAP);
		if (has_invalid_char(map[i]))
			exit_error(INVALID_CHAR, INVALID_MAP);
		i++;
	}
}
