/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/04/11 11:13:49 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	render_player(void)
{
	t_pos	centered_pos;

	centered_pos = center_position(game()->player.pos, PLAYER_SIZE);
	render_square((t_square){centered_pos, PLAYER_SIZE, CYAN});
	render_square((t_square){centered_pos, PLAYER_SIZE, RED});
}

static void	render_fov(void)
{
	t_pos	centered_pos;
	t_pos	cam_start_pos;

	centered_pos = center_position(game()->player.pos, TILE_SIZE);
	cam_start_pos.x = centered_pos.x + game()->player.dir.x * TILE_SIZE;
	cam_start_pos.y = centered_pos.y + game()->player.dir.y * TILE_SIZE;
	render_line(centered_pos, game()->player.dir, 30, RED);
	render_line(cam_start_pos, game()->player.camera, 5, RED);
	render_line(cam_start_pos, reverse_dir(game()->player.camera), 5, RED);
}

void	render_minimap(void)
{
	int	i;
	int	j;

	i = -1;
	while (game()->map[++i])
	{
		j = -1;
		while (game()->map[i][++j])
		{
			if (is_wall(game()->map[i][j]))
				render_square((t_square){to_screen_pos((t_pos){j, i}),
					TILE_SIZE, BLUE});
			else if (is_floor(game()->map[i][j]))
				render_square((t_square){to_screen_pos((t_pos){j, i}),
					TILE_SIZE, CYAN});
		}
	}
	render_player();
	render_fov();
}
