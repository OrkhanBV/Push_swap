/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:08:35 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 15:01:19 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_best(t_ab *ab)
{
	t_list	*b_iter;
	int		nbr_best_elem;
	int		i;
	int		min_res;

	b_iter = ab->b;
	min_res = b_iter->res;
	i = 0;
	while (b_iter)
	{
		if (b_iter->res <= min_res)
		{
			min_res = b_iter->res;
			nbr_best_elem = i;
		}
		i++;
		b_iter = b_iter->next;
	}
	return (nbr_best_elem);
}
