/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_step_res.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:33:38 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 15:07:43 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**            здесь мы сравниваем направление сдвига А и В
**         и находим наименьшее число ходов для каждого  элемента Б
*/

int		find_the_res(t_list **b_list)
{
	int			min_run_b;
	int			min_run_a;
	t_list		*b;

	b = *b_list;
	if (b->run_al > b->run_ar)
		min_run_a = b->run_ar;
	else
		min_run_a = b->run_al;
	if (b->run_bl > b->run_br)
		min_run_b = b->run_br;
	else
		min_run_b = b->run_bl;
	b->res = min_run_a + min_run_b;
	return (b->res);
}

/*
**     материнская функция в которой мы прокручиваем В листы
**              прописывая для каждого В
**  сколько нужно прокрутить А и сколько нужно прокрутить сам В
*/

void	count_step_b(t_ab *ab)
{
	t_list	*b_iter;
	int		size;
	int		i;

	b_iter = ab->b;
	size = size_of_list(&(ab->b));
	i = 0;
	while (i <= size)
	{
		b_iter->run_br = i;
		b_iter->run_bl = (size - i + 1);
		b_iter->run_ar = count_run_ar(&(ab->a), &b_iter);
		b_iter->run_al = count_run_al(&(ab->a), &b_iter);
		b_iter->res = find_the_res(&b_iter);
		b_iter = b_iter->next;
		i++;
	}
	return ;
}

void	count_step_b_last(t_ab *ab)
{
	const int		size = size_of_list(&(ab->b));
	int				i;
	t_list			*b_iter;

	i = 0;
	b_iter = ab->b;
	while (i <= size)
	{
		b_iter->run_br = i;
		b_iter->run_bl = (size - i + 1);
		b_iter->run_al = count_run_al_last(&(ab->a), &b_iter);
		b_iter->run_ar = count_run_ar_last(&(ab->a), &b_iter);
		b_iter->res = find_the_res(&b_iter);
		b_iter = b_iter->next;
		i++;
	}
	return ;
}
