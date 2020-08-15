/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:49:46 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:36:00 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		pa(t_list **list_a, t_list **list_b)
{
	t_list	*b_st;
	t_list	*a_st;
	int		new_a_from_b;

	b_st = *list_b;
	a_st = *list_a;
	new_a_from_b = b_st->data;
	*list_a = ft_add_to_top(&a_st, new_a_from_b);
	*list_b = ft_delete_first_elem(&b_st);
	ft_putstr("pa\n");
}

void		pb(t_list **list_a, t_list **list_b)
{
	t_list	*a_st;
	t_list	*b_st;
	int		b;

	a_st = *list_a;
	b_st = *list_b;
	b = a_st->data;
	*list_b = ft_add_to_top(&b_st, b);
	*list_a = ft_delete_first_elem(&a_st);
	ft_putstr("pb\n");
}
