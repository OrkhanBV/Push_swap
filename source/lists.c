/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:01:22 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 16:36:27 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_list		*ft_createlist(int data)
{
	t_list	*list;

	if ((list = (t_list*)malloc(sizeof(t_list))))
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

t_list		*ft_add_to_top(t_list **head, int data)
{
	t_list	*new_head;

	new_head = *head;
	if (new_head == NULL)
	{
		new_head = ft_createlist(data);
		*head = new_head;
	}
	else
	{
		new_head = ft_createlist(data);
		new_head->next = *head;
		*head = new_head;
	}
	return (*head);
}

t_list		*ft_add_to_bottom(t_list **head, int data)
{
	t_list	*new_list;

	new_list = *head;
	if (new_list == NULL)
		*head = ft_createlist(data);
	else
	{
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = ft_createlist(data);
	}
	return (*head);
}

t_list		*ft_delete_first_elem(t_list **list)
{
	t_list *tmp;

	if (*list == NULL)
		return (*list);
	tmp = *list;
	if (tmp)
	{
		tmp = tmp->next;
		if (*list != NULL)
			free(*list);
		*list = tmp;
	}
	return (*list);
}

t_list		*ft_delete_last_elem(t_list **list)
{
	t_list	*iter;

	if (*list == NULL)
		return (NULL);
	if ((*list)->next == NULL)
	{
		free((*list));
		*list = NULL;
		return (*list);
	}
	iter = *list;
	while (iter->next->next != NULL)
		iter = iter->next;
	free(iter->next);
	iter->next = NULL;
	return (*list);
}
