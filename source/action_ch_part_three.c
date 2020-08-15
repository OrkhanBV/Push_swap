/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ch_part_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:26:00 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:29:01 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		rai(t_list **list_a)
{
	t_list	*a_st;
	int		a;

	if (*list_a == NULL)
		return (1);
	a_st = *list_a;
	a = a_st->data;
	*list_a = ft_delete_first_elem(&a_st);
	*list_a = ft_add_to_bottom(&a_st, a);
	return (0);
}

int		rbi(t_list **list_a)
{
	t_list	*a_st;
	int		a;

	if (*list_a == NULL)
		return (1);
	a_st = *list_a;
	a = a_st->data;
	*list_a = ft_delete_first_elem(&a_st);
	*list_a = ft_add_to_bottom(&a_st, a);
	return (0);
}

int		rri(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL || *list_b == NULL)
		return (1);
	if (rai(list_a) == 1)
		return (1);
	if (rbi(list_b) == 1)
		return (1);
	return (0);
}
