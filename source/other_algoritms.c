/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algoritms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:58:30 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 04:58:34 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		for_one_elem_a(t_list **a)
{
	while (check_order(a) != 1)
	{
		if (check_order(a) == 1)
			return ;
		else if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	return ;
}

void		for_three_elem_a(t_list **a)
{
	while (check_order(a) != 1)
	{
		if (check_order(a) == 1)
			return ;
		if ((*a)->data > (*a)->next->next->data &&
					(*a)->data > (*a)->next->data)
			ra(a);
		else if ((*a)->data < (*a)->next->next->data &&
					(*a)->data > (*a)->next->data)
			sa(a);
		else if ((*a)->data < (*a)->next->next->data &&
					(*a)->data < (*a)->next->data)
			ra(a);
		else if ((*a)->data > (*a)->next->next->data &&
					(*a)->data < (*a)->next->data)
			sa(a);
	}
	return ;
}

void		for_two_elem_a(t_list **a)
{
	while (check_order(a) != 1)
	{
		if (check_order(a) == 1)
			return ;
		else if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	return ;
}
