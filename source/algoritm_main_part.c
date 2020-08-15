/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_main_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:18:35 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:46:57 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**Даннная функция крутит и перекидывает из стека А в В в
**соответствии с командами записанными в структуру com
*/

void	run_stacks(t_ab **ab, t_order com)
{
	int i;

	i = -1;
	if (com.direct_a == 1)
		while (++i < com.cnt_a_run)
			ra(&((*ab)->a));
	i = -1;
	if (com.direct_b == 1)
		while (++i < com.cnt_b_run)
			rb(&((*ab)->b));
	i = -1;
	if (com.direct_a == -1)
		while (++i < com.cnt_a_run)
			rra(&((*ab)->a));
	i = -1;
	if (com.direct_b == -1)
		while (++i < com.cnt_b_run)
			rrb(&((*ab)->b));
}

void	run_stacks_last_elem(t_ab **ab, t_order com)
{
	int i;

	i = -1;
	if (com.direct_a == 1)
		while (++i < com.cnt_a_run)
			ra(&((*ab)->a));
	i = -1;
	if (com.direct_b == 1)
		while (++i < com.cnt_b_run)
			rb(&((*ab)->b));
	i = -1;
	if (com.direct_a == -1)
		while (++i < com.cnt_a_run)
			rra(&((*ab)->a));
	i = -1;
	if (com.direct_b == -1)
		while (++i < com.cnt_b_run)
			rrb(&((*ab)->b));
	if (com.direct_b != 0 || com.direct_a != 0)
		pa(&((*ab)->a), &((*ab)->b));
}

void	run_commander(t_ab *ab)
{
	int			nbr_best_elem;
	t_order		com;

	nbr_best_elem = 0;
	count_step_b(ab);
	nbr_best_elem = find_best(ab);
	create_moving_order(nbr_best_elem, ab, &com);
	run_stacks(&ab, com);
	if (com.direct_b != 0 || com.direct_a != 0)
		pa(&(ab->a), &(ab->b));
}

void	run_commander_last(t_ab *ab)
{
	int			nbr_best_elem;
	t_order		com;

	nbr_best_elem = 0;
	count_step_b_last(ab);
	nbr_best_elem = find_best(ab);
	create_moving_order_l(nbr_best_elem, ab, &com);
	run_stacks_last_elem(&ab, com);
	return ;
}

void	main_algoritm(t_ab *ab)
{
	int		i;
	int		j;

	j = size_of_list(&(ab->b));
	i = 0;
	while (i <= (j - 2))
	{
		run_commander(ab);
		i++;
	}
	run_commander_last(ab);
	run_commander_last(ab);
	return ;
}
