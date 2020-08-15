/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_f_stps_res.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:33:22 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:53:23 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ini_zero(t_list *list)
{
	list->run_br = 0;
	list->run_bl = 0;
	list->run_ar = 0;
	list->run_al = 0;
	list->res = 0;
}

void	inicial(t_ab *ab)
{
	t_list *a_iter;
	t_list *b_iter;

	a_iter = ab->a;
	b_iter = ab->b;
	while (b_iter)
	{
		ini_zero(b_iter);
		b_iter = b_iter->next;
	}
	while (a_iter)
	{
		ini_zero(a_iter);
		a_iter = a_iter->next;
	}
}

int		*create_array(t_list **a_or_b, int last)
{
	t_list	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = *a_or_b;
	arr = (int *)malloc((last + 1) * sizeof(int));
	while (tmp && i <= last)
	{
		arr[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}
