/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_algoritm_steps_ar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:57:30 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 04:57:34 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**                      часть кода для count_run_al
*/

int			compare_ar(int *a_list, int i, int last, t_list *b)
{
	int data_b;

	data_b = b->data;
	if (i == 0)
	{
		if (data_b > a_list[last] && data_b < a_list[i])
			return (i);
		if (data_b < a_list[i] && data_b > a_list[i + 1])
			return (i + 1);
	}
	if (i != 0)
	{
		if (data_b < a_list[i] && data_b > a_list[i + 1])
			return (i + 1);
	}
	return (-1);
}

/*
** здесь для конкретного элемента В мы прокручиваем весь А стек в поиске самого
**                          выгодного шага в стеке А
*/

int			count_run_ar(t_list **a, t_list **b_elem)
{
	int			last;
	int			i;
	int			*a_arr;

	last = size_of_list(a);
	a_arr = create_array(a, last);
	i = 0;
	while (i <= last)
	{
		if ((*b_elem)->data < a_arr[0] &&
			(*b_elem)->data > a_arr[last])
		{
			free_int_arr(&a_arr);
			return (0);
		}
		if ((*b_elem)->data > a_arr[i] &&
			(*b_elem)->data < a_arr[i + 1] && (i + 1) <= last)
		{
			free_int_arr(&a_arr);
			return (i + 1);
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

int			count_run_ar_last(t_list **a, t_list **b_elem)
{
	int			last;
	int			i;
	int			*a_arr;

	last = size_of_list(a);
	i = 0;
	a_arr = create_array(a, last);
	while (i <= last)
	{
		if ((*b_elem)->data < a_arr[0] &&
			(*b_elem)->data > a_arr[last])
		{
			free_int_arr(&a_arr);
			return (0);
		}
		if ((*b_elem)->data > a_arr[i] &&
			(*b_elem)->data < a_arr[i + 1] && (i + 1) <= last)
		{
			free_int_arr(&a_arr);
			return (i + 1);
		}
		i++;
	}
	free_int_arr(&a_arr);
	return (0);
}
