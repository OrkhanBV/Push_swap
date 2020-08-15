/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:50:58 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:35:08 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ra(t_list **list_a)
{
	t_list	*a_st;
	int		a;

	a_st = *list_a;
	a = a_st->data;
	*list_a = ft_delete_first_elem(&a_st);
	*list_a = ft_add_to_bottom(&a_st, a);
	ft_putstr("ra\n");
}

void		rb(t_list **list_a)
{
	t_list	*a_st;
	int		a;

	a_st = *list_a;
	a = a_st->data;
	*list_a = ft_delete_first_elem(&a_st);
	*list_a = ft_add_to_bottom(&a_st, a);
	ft_putstr("rb\n");
}

void		rr(t_list **list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
	ft_putstr("rr\n");
}
