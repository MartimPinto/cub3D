/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:30:38 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/22 12:23:41 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	move_player_forward(void)
{
	t_pos	new;

	new.x = game()->player.pos.x + game()->player.dir.x * MOVESPEED;
	new.y = game()->player.pos.y + game()->player.dir.y * MOVESPEED;
	return (validate_move(new));
}

static int	move_player_backward(void)
{
	t_pos	new;

	new.x = game()->player.pos.x - game()->player.dir.x * MOVESPEED;
	new.y = game()->player.pos.y - game()->player.dir.y * MOVESPEED;
	return (validate_move(new));
}

static int	move_player_left(void)
{
	t_pos	new;

	new.x = game()->player.pos.x + game()->player.dir.y * MOVESPEED;
	new.y = game()->player.pos.y - game()->player.dir.x * MOVESPEED;
	return (validate_move(new));
}

static int	move_player_right(void)
{
	t_pos	new;

	new.x = game()->player.pos.x - game()->player.dir.y * MOVESPEED;
	new.y = game()->player.pos.y + game()->player.dir.x * MOVESPEED;
	return (validate_move(new));
}

int	move_player(void)
{
	int	moved;

	moved = 0;
	if (game()->player.move_y == 1)
		moved += move_player_forward();
	if (game()->player.move_y == -1)
		moved += move_player_backward();
	if (game()->player.move_x == -1)
		moved += move_player_left();
	if (game()->player.move_x == 1)
		moved += move_player_right();
	if (game()->player.rotate == 1)
		moved += rotate_camera(RIGHT);
	if (game()->player.rotate == -1)
		moved += rotate_camera(LEFT);
	return (moved);
}
