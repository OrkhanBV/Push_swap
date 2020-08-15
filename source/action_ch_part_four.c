/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ch_part_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:47:34 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:26:58 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		rrai(t_list **list_a)
{
	t_list	*a_last;
	t_list	*a_first;
	int		a;
	int		i;
	int		size;

	if (*list_a == NULL)
		return (1);
	i = 0;
	a_last = *list_a;
	a_first = *list_a;
	size = size_of_list_i(a_first);
	while (i < size)
	{
		a_last = a_last->next;
		i++;
	}
	a = a_last->data;
	*list_a = ft_delete_last_elem(&a_first);
	*list_a = ft_add_to_top(&a_first, a);
	return (0);
}

int		rrbi(t_list **list_b)
{
	t_list	*b_last;
	t_list	*b_first;
	int		b;
	int		i;

	if (*list_b == NULL)
		return (1);
	i = 0;
	b_last = *list_b;
	b_first = *list_b;
	while (i < size_of_list_i(b_first))
	{
		b_last = b_last->next;
		i++;
	}
	b = b_last->data;
	*list_b = ft_delete_last_elem(&b_first);
	*list_b = ft_add_to_top(&b_first, b);
	return (0);
}

int		rrri(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	if (*list_a == NULL || *list_b == NULL)
		return (1);
	a = *list_a;
	b = *list_b;
	if (rrai(list_a) == 1)
		return (1);
	if (rrbi(list_b) == 1)
		return (1);
	return (0);
}
