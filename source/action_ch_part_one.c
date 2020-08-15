/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ch_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:23:27 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:28:18 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sai(t_list **list_a)
{
	t_list	*head;
	int		swap;
	t_list	*a_one;
	t_list	*a_two;

	if (*list_a == NULL)
		return (1);
	head = *list_a;
	a_one = head;
	if (a_one->next == NULL)
		return (1);
	if (a_one)
	{
		swap = a_one->data;
		a_two = head->next;
		a_one->data = a_two->data;
		a_two->data = swap;
	}
	return (0);
}

int		sbi(t_list **list_b)
{
	t_list	*head;
	int		swap;
	t_list	*b_one;
	t_list	*b_two;

	if (*list_b == NULL)
		return (1);
	head = *list_b;
	b_one = head;
	if (b_one->next == NULL)
		return (1);
	if (head)
	{
		swap = b_one->data;
		b_two = b_one->next;
		b_one->data = b_two->data;
		b_two->data = swap;
	}
	return (0);
}

int		ssi(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL || *list_b == NULL)
		return (1);
	if (sai(list_a) == 1)
		return (1);
	if (sbi(list_b) == 1)
		return (1);
	return (0);
}
