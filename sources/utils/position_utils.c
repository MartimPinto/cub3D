/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:43:19 by Axel              #+#    #+#             */
/*   Updated: 2024/04/02 11:58:46 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_pos	to_screen_pos(t_pos pos)
{
	t_pos	screen_pos;

	screen_pos.x = MAP_POS + (TILE_SIZE * pos.x) + ((double)TILE_SIZE / 2);
	screen_pos.y = MAP_POS + (TILE_SIZE * pos.y) + ((double)TILE_SIZE / 2);
	return (screen_pos);
}

t_pos	to_map_pos(t_pos screen_pos)
{
	t_pos	map_pos;

	map_pos.x = (screen_pos.x - MAP_POS) / TILE_SIZE;
	map_pos.y = (screen_pos.y - MAP_POS) / TILE_SIZE;
	return (map_pos);
}

t_pos	reverse_dir(t_pos dir)
{
	t_pos	reversed;

	reversed.x = -dir.x;
	reversed.y = -dir.y;
	return (reversed);
}

t_pos	add_pos(t_pos p1, t_pos p2)
{
	t_pos	added;

	added.x = p1.x + p2.x;
	added.y = p1.y + p2.y;
	return (added);
}

t_pos	center_position(t_pos pos, int size)
{
	double	offset;

	offset = (double)size / 2.0;
	return (add_pos(pos, (t_pos){offset, offset}));
}
