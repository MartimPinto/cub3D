/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:01 by Axel              #+#    #+#             */
/*   Updated: 2024/04/22 14:37:59 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rotate_camera(t_rotation direction)
{
	double		angle;
	t_player	*p;

	p = &game()->player;
	angle = ROTSPEED;
	if (direction == LEFT)
		angle = -angle;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = p->dir.x * sin(angle) + p->dir.y * cos(angle);
	p->camera.x = p->camera.x * cos(angle) - p->camera.y * sin(angle);
	p->camera.y = p->camera.x * sin(angle) + p->camera.y * cos(angle);
	game()->player.has_moved = 1;
	return (EXIT_SUCCESS);
}

int	key_press(int keycode)
{
	if (keycode == KEY_W)
		game()->player.move_y += 1;
	else if (keycode == KEY_S)
		game()->player.move_y += -1;
	else if (keycode == KEY_D)
		game()->player.move_x += 1;
	else if (keycode == KEY_A)
		game()->player.move_x += -1;
	else if (keycode == KEY_RIGHT)
		game()->player.rotate += 1;
	else if (keycode == KEY_LEFT)
		game()->player.rotate += -1;
	else if (keycode == KEY_ENTER)
	{
		game()->map_info->render_map = true;
		game()->player.has_moved = 1;
	}
	else if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_release(int keycode)
{
	if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	if (keycode == KEY_W && game()->player.move_y >= 1)
		game()->player.move_y = 0;
	if (keycode == KEY_S && game()->player.move_y <= -1)
		game()->player.move_y = 0;
	if (keycode == KEY_A && game()->player.move_x <= -1)
		game()->player.move_x = 0;
	if (keycode == KEY_D && game()->player.move_x >= 1)
		game()->player.move_x = 0;
	if (keycode == KEY_LEFT && game()->player.rotate <= 1)
		game()->player.rotate = 0;
	if (keycode == KEY_RIGHT && game()->player.rotate >= -1)
		game()->player.rotate = 0;
	game()->player.has_moved = 0;
	return (EXIT_SUCCESS);
}

static void	wrap_mouse_position(int x, int y)
{
	if (x > SCREEN_W - MOUSE_WRAP)
	{
		x = SCREEN_W - MOUSE_WRAP;
		mlx_mouse_move(game()->mlx, game()->mlx_win, x, y);
	}
	if (x < MOUSE_WRAP)
	{
		x = MOUSE_WRAP;
		mlx_mouse_move(game()->mlx, game()->mlx_win, x, y);
	}
}

int	mouse_handler(int x, int y)
{
	static int	old_x;

	old_x = SCREEN_W / 2;
	wrap_mouse_position(x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		game()->player.has_moved += rotate_camera(LEFT);
	else if (x > old_x)
		game()->player.has_moved += rotate_camera(RIGHT);
	old_x = x;
	return (EXIT_SUCCESS);
}
