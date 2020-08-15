/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_steps_al.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:06:28 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 15:13:48 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**                      часть кода для count_run_al
*/

int			compare_al(int *a_list, int last, int i, t_list *b)
{
	int data_b;

	data_b = b->data;
	if (last - i <= 0)
	{
		if (data_b < a_list[0] && data_b > a_list[last])
			return (last);
	}
	if ((data_b < a_list[last - i] && (last - i) >= 0) &&
	((last - 1 - i) >= 0 && data_b > a_list[last - 1 - i]))
		return (i + 1);
	return (-1);
}

/*
** здесь для конкретного элемента В мы прокручиваем весь А стек в поиске самого
**                          выгодного шага в стеке А
*/

int			count_run_al(t_list **a, t_list **b_elem)
{
	int			last;
	int			i;
	int			res;
	int			*a_arr;

	last = size_of_list(a);
	a_arr = create_array(a, last);
	i = 0;
	while (i <= last)
	{
		if (compare_al(a_arr, last, i, *b_elem) != -1)
		{
			res = compare_al(a_arr, last, i, *b_elem);
			free_int_arr(&a_arr);
			return (res);
		}
		i++;
	}
	free_int_arr(&a_arr);
	return (0);
}

/*
**      здесь мы последнего и предпоследнего  В смотрим сколко нужно прокрутить
**                                      стек А
*/

int			count_run_al_last(t_list **a, t_list **b_elem)
{
	int			last;
	int			i;
	int			*a_arr;

	last = size_of_list(a);
	a_arr = create_array(a, last);
	i = 0;
	while (last > 0)
	{
		if ((*b_elem)->data < a_arr[last] &&
			(*b_elem)->data > a_arr[last - 1] &&
			(i + 1) <= last)
		{
			free_int_arr(&a_arr);
			return (last);
		}
		last--;
	}
	free_int_arr(&a_arr);
	return (0);
}
