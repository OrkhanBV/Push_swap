/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:47:36 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:34:48 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sa(t_list **list_a)
{
	t_list	*head;
	int		swap;
	t_list	*a_one;
	t_list	*a_two;

	head = *list_a;
	a_one = head;
	if (a_one)
	{
		swap = a_one->data;
		a_two = head->next;
		a_one->data = a_two->data;
		a_two->data = swap;
	}
	ft_putstr("sa\n");
}

void		sb(t_list **list_b)
{
	t_list	*head;
	int		swap;
	t_list	*b_one;
	t_list	*b_two;

	head = *list_b;
	b_one = head;
	if (head)
	{
		swap = b_one->data;
		b_two = b_one->next;
		b_one->data = b_two->data;
		b_two->data = swap;
	}
	ft_putstr("sb\n");
}

void		ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sb(list_b);
	ft_putstr("ss\n");
}
