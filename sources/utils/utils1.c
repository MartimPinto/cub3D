/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:39 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/24 18:00:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

bool	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (true);
	return (false);
}

char	*trim_elements(char *str, char **chars)
{
	char	*substring;
	char	*new;
	int		i;

	i = 0;
	while (chars[i])
	{
		substring = ft_strstr(str, chars[i]);
		if (substring)
		{
			new = ft_substr(substring, 0, ft_strlen(substring));
			if (!new)
				return (NULL);
			return (new);
		}
		i++;
	}
	return (ft_strdup(str));
}

void	cleaner(char *str, char **var)
{
	int		i;
	int		j;

	if (!str && !*str)
		return ;
	if (*var)
	{
		game()->error = true;
		return ;
	}
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	j = ft_strlen(str) - 1;
	while (ft_isspace(str[j]))
		j--;
	if (str[j] == '\n')
		j--;
	*var = ft_substr(str, i, j - i + 1);
}

bool	order_check(void)
{
	if (game()->map_info->arr[0] != NULL)
	{
		if ((game()->map_info->no == NULL || game()->map_info->no[0] == '\0')
			&& (game()->map_info->so == NULL
				|| game()->map_info->so[0] == '\0')
			&& (game()->map_info->we == NULL
				|| game()->map_info->we[0] == '\0')
			&& (game()->map_info->ea == NULL
				|| game()->map_info->ea[0] == '\0')
			&& (game()->map_info->f == NULL
				|| game()->map_info->f[0] == '\0')
			&& (game()->map_info->c == NULL
				|| game()->map_info->c[0] == '\0'))
		{
			return (false);
		}
		else
			return (true);
	}
	return (true);
}
