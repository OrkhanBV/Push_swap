/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algoritms_sorting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:58:02 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 04:58:06 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		for_three_elem(t_ab *ab)
{
	while (check_order(&(ab->a)) != 1)
	{
		if (check_order(&(ab->a)) == 1)
			return ;
		if (ab->a->data > ab->a->next->next->data &&
				ab->a->data > ab->a->next->data)
			ra(&(ab->a));
		else if (ab->a->data < ab->a->next->next->data &&
				ab->a->data > ab->a->next->data)
			sa(&(ab->a));
		else if (ab->a->data < ab->a->next->next->data &&
				ab->a->data < ab->a->next->data)
			ra(&(ab->a));
		else if (ab->a->data > ab->a->next->next->data &&
				ab->a->data < ab->a->next->data)
			sa(&(ab->a));
	}
	return ;
}

void		sort_b_send_to_a(t_ab *ab)
{
	while (check_order(&ab->b) == 1)
	{
		if (check_order(&ab->b) != 1)
		{
			pa(&(ab->a), &(ab->b));
			pa(&(ab->a), &(ab->b));
			return ;
		}
		else if (ab->b->data < ab->b->next->data)
			sb(&(ab->b));
	}
	pa(&(ab->a), &(ab->b));
	pa(&(ab->a), &(ab->b));
	return ;
}

void		for_two_elem_b(t_list **b)
{
	while (check_order(b) == 1)
	{
		if (check_order(b) != 1)
			return ;
		else if ((*b)->data < (*b)->next->data)
			sb(b);
	}
	return ;
}

void		for_five_elem(t_ab *ab, int size)
{
	int		*arr;
	int		median;
	int		i;

	i = 0;
	arr = create_arr_from_list(&(ab->a), size);
	median = medi(arr, size);
	while (i < 4)
	{
		if ((ab->a->data) >= median)
			ra(&(ab->a));
		if (((ab->a->data) < median))
			pb(&(ab->a), &(ab->b));
		i++;
	}
	if (arr)
		free(arr);
	for_three_elem_a(&(ab->a));
	sort_b_send_to_a(ab);
	return ;
}

void		for_four_elem(t_ab *ab, int size)
{
	int		*arr;
	int		median;
	int		i;

	i = 0;
	arr = create_arr_from_list(&(ab->a), size);
	median = medi(arr, size);
	while (i < size)
	{
		if ((ab->a->data) >= median)
			ra(&(ab->a));
		if (((ab->a->data) < median))
			pb(&(ab->a), &(ab->b));
		i++;
	}
	for_three_elem_a(&(ab->a));
	pa(&(ab->a), &(ab->b));
	free(arr);
	return ;
}
