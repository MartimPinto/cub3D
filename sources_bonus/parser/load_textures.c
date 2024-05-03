/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:44:32 by Axel              #+#    #+#             */
/*   Updated: 2024/04/15 10:56:34 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	load_color(char *str, char type)
{
	int		red;
	int		green;
	int		blue;
	int		*color;
	char	**colors;

	if (type == 'c')
		color = &game()->text_info->c;
	else
		color = &game()->text_info->f;
	colors = ft_split(str, ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	*color = create_trgb(0, red, green, blue);
	free_matrix(colors);
}

static void	init_text_img(t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game()->mlx, path,
			&(game()->text_info->size), &(game()->text_info->size));
	if (!img->img)
		exit_error(ALLOC_ERROR, "xpm_file_to_img");
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bbp, &img->line_length,
			&img->endian);
}

static int	*load_texture(char *path)
{
	t_img	img;
	int		*buff;
	int		x;
	int		y;

	init_text_img(&img, path);
	buff = ft_calloc(1, game()->text_info->size * game()->text_info->size
			* sizeof(int));
	if (!buff)
		exit_error(ALLOC_ERROR, "load textures");
	y = -1;
	while (++y < game()->text_info->size)
	{
		x = -1;
		while (++x < game()->text_info->size)
			buff[y * game()->text_info->size + x] = img.addr[y
				* game()->text_info->size + x];
	}
	mlx_destroy_image(game()->mlx, img.img);
	return (buff);
}

void	load_textures(void)
{
	game()->map = game()->map_info->arr;
	load_color(game()->map_info->f, 'f');
	load_color(game()->map_info->c, 'c');
	game()->textures[NORTH] = load_texture(game()->map_info->no);
	game()->textures[SOUTH] = load_texture(game()->map_info->so);
	game()->textures[WEST] = load_texture(game()->map_info->we);
	game()->textures[EAST] = load_texture(game()->map_info->ea);
}
