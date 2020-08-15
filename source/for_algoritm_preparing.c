/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_preparing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:38:45 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 15:04:29 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		block_of_body(t_ab *ab, int mediana, int max, int min)
{
	if (((ab->a->data) != max) && ((ab->a->data) != min))
	{
		if (((ab->a->data) <= mediana) &&
				(ab->a->data) != max &&
				(ab->a->data) != min)
		{
			pb(&(ab->a), &(ab->b));
			rb(&(ab->b));
		}
		if ((ab->a->data > mediana) &&
				(ab->a->data) != max &&
				(ab->a->data) != min)
		{
			pb(&(ab->a), &(ab->b));
		}
	}
	return ;
}

static void		body_of_preparing(t_ab *ab, int max, int min, int size)
{
	int		i;
	int		mediana;
	int		*arr;

	arr = create_arr_from_list(&(ab->a), size);
	mediana = medi(arr, size);
	free(arr);
	i = 0;
	while (i <= (size))
	{
		if ((ab->a->data) == max || (ab->a->data) == min)
		{
			ra(&(ab->a));
		}
		block_of_body(ab, mediana, max, min);
		i++;
	}
}

void			preparing_ab(t_ab *ab, int size)
{
	int			max;
	int			min;

	max = f_max(&(ab->a));
	min = f_min(&(ab->a));
	body_of_preparing(ab, max, min, size);
}
