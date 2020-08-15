/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:41:29 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 16:42:34 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			steps_before_min(t_ab *ab)
{
	t_list	*a_tmp;
	int		step;
	int		min;

	step = 0;
	min = 0;
	a_tmp = ab->a;
	min = f_min(&a_tmp);
	while (a_tmp)
	{
		if (a_tmp->data == min)
			return (step - 1);
		step++;
		a_tmp = a_tmp->next;
	}
	return (0);
}

int			steps_after_min(t_ab *ab)
{
	t_list	*a_tmp;
	int		step;
	int		signal;
	int		min;

	a_tmp = ab->a;
	step = 0;
	signal = 0;
	min = 0;
	min = f_min(&a_tmp);
	while (a_tmp)
	{
		if (a_tmp->data == min)
			signal = 1;
		if (signal == 1)
			step++;
		a_tmp = a_tmp->next;
	}
	return (step);
}

void		finish_a(t_ab *ab)
{
	int i;
	int step_ar;
	int step_rra;

	i = 0;
	step_ar = steps_before_min(ab);
	step_rra = steps_after_min(ab);
	if (step_ar >= step_rra)
		while (check_order(&ab->a) != 1)
		{
			if (check_order(&ab->a) == 1)
				return ;
			rra(&ab->a);
			i++;
		}
	else
		while (check_order(&ab->a) != 1)
		{
			if (check_order(&ab->a) == 1)
				return ;
			ra(&ab->a);
			i++;
		}
	return ;
}
