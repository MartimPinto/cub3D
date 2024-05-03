/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/04/17 15:39:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	print_commands(void)
{
	printf("\n");
	printf(" ██████╗██╗   ██╗██████╗ ██████╗ ██████╗\n");
	printf("██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n");
	printf("██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n");
	printf("██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n");
	printf("╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n");
	printf(" ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \n");
	printf("forward: w\t\tbackward: s\n");
	printf("left: a\t\t\tright: d\n");
	printf("rotate left: ←\t\trotate right: →\n");
	printf("print map: ↵\n");
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		exit_error(USAGE, NULL);
	print_commands();
	init_game();
	parse_file(argv[1]);
	start_game();
	return (EXIT_SUCCESS);
}
