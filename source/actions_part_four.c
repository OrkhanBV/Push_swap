/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:12:06 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:34:15 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		rra(t_list **list_a)
{
	t_list	*a_last;
	t_list	*a_first;
	int		a;
	int		i;
	int		size;

	i = 0;
	a_last = *list_a;
	a_first = *list_a;
	size = size_of_list(&a_first);
	while (i < size)
	{
		a_last = a_last->next;
		i++;
	}
	a = a_last->data;
	*list_a = ft_delete_last_elem(&a_first);
	*list_a = ft_add_to_top(&a_first, a);
	ft_putstr("rra\n");
}

void		rrb(t_list **list_b)
{
	t_list	*b_last;
	t_list	*b_first;
	int		b;
	int		i;

	i = 0;
	b_last = *list_b;
	b_first = *list_b;
	while (i < size_of_list(&b_first))
	{
		b_last = b_last->next;
		i++;
	}
	b = b_last->data;
	*list_b = ft_delete_last_elem(&b_first);
	*list_b = ft_add_to_top(&b_first, b);
	ft_putstr("rrb\n");
}

void		rrr(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	rra(list_a);
	rrb(list_b);
	ft_putstr("rrr\n");
}
