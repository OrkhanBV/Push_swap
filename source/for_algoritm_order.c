/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:12:53 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 17:39:09 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		inicial_order_list(t_order *com)
{
	com->cnt_a_run = 0;
	com->direct_a = 0;
	com->cnt_b_run = 0;
	com->direct_b = 0;
}

void		write_order_command(t_list **b, t_order *com)
{
	if ((*b)->run_al >= (*b)->run_ar)
	{
		com->cnt_a_run = (*b)->run_ar;
		com->direct_a = 1;
	}
	if ((*b)->run_al <= (*b)->run_ar)
	{
		com->cnt_a_run = (*b)->run_al;
		com->direct_a = -1;
	}
	if ((*b)->run_bl >= (*b)->run_br)
	{
		com->cnt_b_run = (*b)->run_br;
		com->direct_b = 1;
	}
	if ((*b)->run_bl <= (*b)->run_br)
	{
		com->cnt_b_run = (*b)->run_bl;
		com->direct_b = -1;
	}
}

void		write_order_command_l(t_list **b, t_order *com)
{
	if ((*b)->run_al >= (*b)->run_ar)
	{
		com->cnt_a_run = (*b)->run_ar;
		com->direct_a = 1;
	}
	if ((*b)->run_al < (*b)->run_ar)
	{
		com->cnt_a_run = (*b)->run_al;
		com->direct_a = -1;
	}
	if ((*b)->run_bl >= (*b)->run_br)
	{
		com->cnt_b_run = (*b)->run_br;
		com->direct_b = 1;
	}
	if ((*b)->run_bl < (*b)->run_br)
	{
		com->cnt_b_run = (*b)->run_bl;
		com->direct_b = -1;
	}
}

void		create_moving_order(int nbr, t_ab *ab, t_order *com)
{
	t_list		*b_iter;
	int			i;

	b_iter = ab->b;
	inicial_order_list(com);
	i = 0;
	while (i <= nbr)
	{
		if (i == nbr)
			write_order_command(&b_iter, com);
		i++;
		b_iter = b_iter->next;
	}
}

void		create_moving_order_l(int nbr, t_ab *ab, t_order *com)
{
	t_list		*b_iter;
	int			i;

	b_iter = ab->b;
	i = 0;
	inicial_order_list(com);
	while (i <= nbr)
	{
		if (i == nbr)
		{
			write_order_command_l(&b_iter, com);
			return ;
		}
		i++;
		if (b_iter->next != 0)
			b_iter = b_iter->next;
	}
}
