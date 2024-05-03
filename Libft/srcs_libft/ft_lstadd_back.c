/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:07:04 by axel              #+#    #+#             */
/*   Updated: 2023/11/29 13:09:21 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*tmp;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new_node;
	}
}
