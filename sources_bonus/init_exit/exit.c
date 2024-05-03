/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/04/22 14:51:33 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	exit_error(char *err_msg, char *var)
{
	ft_putstr_fd(ANSIRED, STDERR_FILENO);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	if (var)
	{
		ft_putstr_fd(var, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit_game(EXIT_FAILURE);
}

void	exit_game(int exit_status)
{
	if (game()->screen_buff.img)
		mlx_destroy_image(game()->mlx, game()->screen_buff.img);
	if (game()->mlx_win)
		mlx_destroy_window(game()->mlx, game()->mlx_win);
	if (game()->mlx)
	{
		mlx_destroy_display(game()->mlx);
		free(game()->mlx);
	}
	if (game()->map_info)
		free_map_info();
	if (game()->text_info)
		free(game()->text_info);
	if (game()->textures)
		free_textures();
	exit(exit_status);
}

int	quit_window(void)
{
	exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
