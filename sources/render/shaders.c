/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:53:48 by Axel              #+#    #+#             */
/*   Updated: 2024/04/15 10:57:29 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	shader(double wall_dist, int color)
{
	double	attenuation_coef;

	if (wall_dist > RENDER_DIST)
		return (BLACK);
	attenuation_coef = (RENDER_DIST - wall_dist) / RENDER_DIST;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}

int	shader_ceiling(int dist, int color)
{
	double	attenuation_coef;
	double	s;

	s = (double)SCREEN_H / 2;
	attenuation_coef = (s - dist) / s;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}

int	shader_floor(int dist, int color)
{
	double	attenuation_coef;
	double	s;

	s = (double)SCREEN_H / 2;
	attenuation_coef = (dist - s) / s;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}
