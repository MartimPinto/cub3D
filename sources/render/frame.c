/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:34 by Axel              #+#    #+#             */
/*   Updated: 2024/04/21 15:25:44 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

static void	clear_screen_buffer(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, BLACK);
	}
}

static void	render_ceiling(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H / 2)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, shader_ceiling(i,
					game()->text_info->c));
	}
}

static void	render_floor(void)
{
	int	i;
	int	j;

	i = SCREEN_H / 2 - 1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, shader_floor(i, game()->text_info->f));
	}
}

int	render_frame(void)
{
	game()->player.has_moved += move_player();
	if (game()->player.has_moved == 0)
		return (EXIT_SUCCESS);
	clear_screen_buffer();
	render_ceiling();
	render_floor();
	raycaster();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win,
		game()->screen_buff.img, 0, 0);
	game()->map_info->render_map = false;
	game()->player.has_moved = 0;
	return (EXIT_SUCCESS);
}
