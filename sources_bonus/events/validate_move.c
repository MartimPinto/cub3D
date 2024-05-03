/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:47 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/22 14:36:05 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	is_map_cell(t_pos next_pos)
{
	if (next_pos.x < 0 || next_pos.y < 0
		|| next_pos.x > get_row_size(next_pos.y)
		|| next_pos.y > get_col_size())
		return (false);
	return (true);
}

int	validate_move(t_pos next_pos)
{
	t_pos	next;
	int		moved;

	next = to_map_pos(next_pos);
	moved = 0;
	if (!is_map_cell(next)
		|| is_wall(game()->map_info->arr[(int)next.y][(int)next.x]))
		return (moved);
	game()->player.pos = next_pos;
	return (++moved);
}
