/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:44:02 by Axel              #+#    #+#             */
/*   Updated: 2024/04/21 14:21:46 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_ray(t_ray *ray, int curr_x)
{
	double		x_cam;
	t_player	p;

	p = game()->player;
	x_cam = 2 * (double)curr_x / SCREEN_W - 1;
	ray->pos = to_map_pos(p.pos);
	ray->dir.x = p.dir.x + p.camera.x * x_cam;
	ray->dir.y = p.dir.y + p.camera.y * x_cam;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	set_side_dist(t_ray *ray)
{
	if (ray->dir.x > 0)
	{
		ray->step.x = 1;
		ray->side_dist.x = ((int)ray->pos.x + 1 - ray->pos.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - (int)ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y > 0)
	{
		ray->step.y = 1;
		ray->side_dist.y = ((int)ray->pos.y + 1 - ray->pos.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - (int)ray->pos.y) * ray->delta_dist.y;
	}
}

static void	perform_dda(t_ray *ray)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else if (ray->side_dist.x > ray->side_dist.y)
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (is_wall(game()->map[(int)ray->pos.y][(int)ray->pos.x]))
			hit = 1;
	}
}

static void	get_line_height(t_ray *ray)
{
	t_pos	curr;

	curr = to_map_pos(game()->player.pos);
	if (!ray->side)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(SCREEN_W / ray->wall_dist);
	ray->start = -ray->line_height / 2 + SCREEN_W / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_height / 2 + SCREEN_W / 2;
	if (ray->end >= SCREEN_W)
		ray->end = SCREEN_W - 1;
	if (!ray->side)
		ray->wall_x = curr.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = curr.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycaster(void)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_W)
	{
		init_ray(&ray, x);
		set_side_dist(&ray);
		perform_dda(&ray);
		get_line_height(&ray);
		render_texture(&ray, x);
		x++;
	}
}
