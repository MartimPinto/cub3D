/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:28:58 by Axel              #+#    #+#             */
/*   Updated: 2024/04/13 20:17:55 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

size_t	get_matrix_len(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	matrix_append(char ***matrix_ptr, char *to_append)
{
	char	**matrix;
	char	**new_matrix;
	int		i;

	matrix = *matrix_ptr;
	new_matrix = ft_calloc(sizeof(char *), get_matrix_len(matrix) + 2);
	if (!new_matrix)
		exit_error("matrix append", ALLOC_ERROR);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strtrim(matrix[i], "\n");
		i++;
	}
	new_matrix[i++] = ft_strtrim(to_append, "\n");
	new_matrix[i] = NULL;
	free_matrix(matrix);
	*matrix_ptr = new_matrix;
}
