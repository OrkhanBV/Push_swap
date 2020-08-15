/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_size_of_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:31:18 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 16:33:15 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int			len_of_list(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			size_of_list(t_list **list)
{
	t_list	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = *list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}

int			size_of_list_i(t_list *list)
{
	t_list	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}
