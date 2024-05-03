/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:25 by Axel              #+#    #+#             */
/*   Updated: 2024/04/18 14:54:07 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_map_info(void)
{
	free_matrix(game()->map_info->arr);
	free(game()->map_info->no);
	free(game()->map_info->so);
	free(game()->map_info->we);
	free(game()->map_info->ea);
	free(game()->map_info->c);
	free(game()->map_info->f);
	free(game()->map_info);
}

void	free_textures(void)
{
	int	i;

	i = -1;
	while (++i < 5)
		free(game()->textures[i]);
	free(game()->textures);
}
