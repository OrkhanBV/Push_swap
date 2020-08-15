/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:48:10 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:36:39 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	manage_two(t_ab *ab)
{
	for_two_elem_a(&(ab->a));
}

static void	manage_three(t_ab *ab)
{
	for_three_elem(ab);
}

static void	manage_four_five(t_ab *ab, int len_stack)
{
	if (len_stack == 5)
		for_five_elem(ab, (len_stack - 1));
	else if (len_stack == 4)
		for_four_elem(ab, (len_stack - 1));
	return ;
}

static void	manage_more_elem(t_ab *ab, int len_stack)
{
	preparing_ab(ab, (len_stack));
	main_algoritm(ab);
	finish_a(ab);
}

void		algo_manager(t_ab *ab)
{
	int			len_stack;

	len_stack = len_of_list(&(ab->a));
	if (len_stack == 1)
		return ;
	else if (len_stack == 2)
		manage_two(ab);
	else if (len_stack == 3)
		manage_three(ab);
	else if (len_stack == 4 || len_stack == 5)
		manage_four_five(ab, len_stack);
	else if (len_stack > 5)
		manage_more_elem(ab, len_stack);
	return ;
}
